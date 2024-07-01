// AllClasses.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <ctime>

std::string toLower(const std::string& s) {
    std::string result;
    for (char c : s) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            result += std::tolower(static_cast<unsigned char>(c));
        }
    }
    return result;
}

class Item {
public:
    std::string name;
    std::string description;

    Item(const std::string& itemName, const std::string& itemDescription) 
        : name(itemName), description(itemDescription) {}
};


// Puzzle class
class Puzzle {
public:
    std::string name;
    std::string description;
    std::string answer;
    bool solved;
    int attempts;
    static const int MAX_ATTEMPTS = 3;

    Puzzle(const std::string& puzName, const std::string& puzDescription, const std::string& puzAnswer)
        : name(puzName), description(puzDescription), answer(puzAnswer), solved(false), attempts(0) {}

    bool attemptSolve(const std::string& attempt) {
        attempts++;
        if (attempt == answer) {
            solved = true;
            return true;
        }
        return false;
    }

    bool hasAttemptsLeft() const {
        return attempts < MAX_ATTEMPTS;
    }
};

// Character class
class Character {
public:
    std::string name;
    std::string description;
    std::string catchphrase;
    std::vector<std::string> actions;

    Character(const std::string& charName, const std::string& charDescription, 
              const std::string& charCatchphrase, const std::vector<std::string>& charActions)
        : name(charName), description(charDescription), catchphrase(charCatchphrase), actions(charActions) {}

    void speak() const {
        std::cout << name << " says: " << catchphrase << std::endl;
    }

    void performAction() const {
        if (!actions.empty()) {
            std::cout << name << " performs an action: " << actions[rand() % actions.size()] << std::endl;
        }
    }

    void showDetails() const {
        std::cout << "Name: " << name << "\nDescription: " << description << "\nCatchphrase: " << catchphrase << std::endl;
        std::cout << "Possible actions: ";
        for (const auto& action : actions) {
            std::cout << action << ", ";
        }
        std::cout << std::endl;
    }
};


// Location class
class Location {
public:
    std::string name;
    std::string description;
    std::map<std::string, Location*> exits;
    std::vector<Item> items;
    std::vector<Character> characters;
    std::vector<Puzzle> puzzles;
    mutable bool firstVisit;
    std::string longDescription;
    bool isLocked;
    std::string requiredItem;

    Location(const std::string& locName, const std::string& locDescription, const std::string& locLongDescription) 
        : name(locName), description(locDescription), longDescription(locLongDescription), firstVisit(true), isLocked(false) {}

    virtual ~Location() {}

    void addItem(const Item& item) {
        items.push_back(item);
    }

    void addCharacter(const Character& character) {
        characters.push_back(character);
    }

    void addPuzzle(const Puzzle& puzzle) {
        puzzles.push_back(puzzle);
    }

    virtual void showDetails() const {
        if (firstVisit) {
            std::cout << longDescription << std::endl;
            firstVisit = false;
        } else {
            std::cout << "You are at " << name << " again." << std::endl;
            std::cout << description << std::endl;
        }

        if (!items.empty()) {
            std::cout << "You see:" << std::endl;
            for (std::vector<Item>::const_iterator it = items.begin(); it != items.end(); ++it) {
                std::cout << "- " << it->name << ": " << it->description << std::endl;
            }
        }
        if (!characters.empty()) {
            std::cout << "Characters here:" << std::endl;
            for (std::vector<Character>::const_iterator it = characters.begin(); it != characters.end(); ++it) {
                std::cout << "- " << it->name << ": " << it->description << std::endl;
            }
        }
    }

    void lock(const std::string& itemNeeded) {
        isLocked = true;
        requiredItem = itemNeeded;
    }

    bool unlock(const std::string& itemName) {
        if (itemName == requiredItem) {
            isLocked = false;
            return true;
        }
        return false;
    }

    Item takeItem(const std::string& itemName, bool& itemTaken) {
        std::vector<Item>::iterator it = std::find_if(items.begin(), items.end(), 
            [&itemName](const Item& item) { 
                return toLower(item.name) == toLower(itemName); 
            });
        if (it != items.end()) {
            Item item = *it;
            items.erase(it);
            itemTaken = true;
            return item;
        }
        itemTaken = false;
        return Item("", "");
    }

    class ItemNameMatcher {
    public:
        explicit ItemNameMatcher(const std::string& name) : name_(toLower(name)) {}
        bool operator()(const Item& item) const { 
            return toLower(item.name) == name_; 
        }
    private:
        std::string name_;
    };

};





// Actions class
class Actions {
private:
    std::map<std::string, std::vector<std::string>> actionSynonyms;
    std::map<std::string, std::string> directionShortcuts;

    static std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(" \t");
        if (std::string::npos == first) {
            return str;
        }
        size_t last = str.find_last_not_of(" \t");
        return str.substr(first, (last - first + 1));
    }

public:
    Actions() {
        actionSynonyms["go"] = {"move", "walk", "travel", "g"};
        actionSynonyms["take"] = {"pick", "grab", "get", "t"};
        actionSynonyms["use"] = {"utilize", "employ", "u"};
        actionSynonyms["look"] = {"examine", "inspect", "l"};
        actionSynonyms["inventory"] = {"items", "i"};
        actionSynonyms["quit"] = {"exit", "q"};
        actionSynonyms["throw"] = {"toss", "hurl"};

        directionShortcuts["n"] = "north";
        directionShortcuts["s"] = "south";
        directionShortcuts["e"] = "east";
        directionShortcuts["w"] = "west";
        directionShortcuts["u"] = "up";
        directionShortcuts["d"] = "down";
    }

    void loadFromFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file) {
            throw std::runtime_error("Unable to open file: " + filePath);
        }
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string action;
            std::string synonym;
            if (std::getline(iss, action, ':')) {
                std::vector<std::string> synonyms;
                while (std::getline(iss, synonym, ',')) {
                    synonyms.push_back(trim(synonym));
                }
                actionSynonyms[trim(action)] = synonyms;
            }
        }
    }

    std::string getBaseAction(const std::string& input) const {
        std::string lowerInput = toLower(input);
        for (const auto& pair : actionSynonyms) {
            if (lowerInput == toLower(pair.first) || 
                std::find_if(pair.second.begin(), pair.second.end(), 
                    [&lowerInput](const std::string& syn) { return toLower(syn) == lowerInput; }) 
                != pair.second.end()) {
                return pair.first;
            }
        }
        return input;
    }

    std::string expandDirection(const std::string& input) const {
        auto it = directionShortcuts.find(input);
        if (it != directionShortcuts.end()) {
            return it->second;
        }
        return input;
    }
};

// Control class
class Control {
private:
    Actions actions;

public:
    Control() {}

    void loadActions(const std::string& filePath) {
        actions.loadFromFile(filePath);
    }

    std::pair<std::string, std::string> parseInput(const std::string& input) {
        std::istringstream iss(input);
        std::string action;
        std::string object;

        iss >> action;
        std::getline(iss, object);

        // Remove leading/trailing whitespace from object
        object.erase(0, object.find_first_not_of(" \t"));
        object.erase(object.find_last_not_of(" \t") + 1);

        // Convert action to lowercase
        std::transform(action.begin(), action.end(), action.begin(), ::tolower);

        // Get base action
        std::string baseAction = actions.getBaseAction(toLower(action));
        return std::make_pair(baseAction, object);
    }
};

// Inventory class
class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const Item& item) {
        items.push_back(item);
    }

    void showInventory() const {
        std::cout << "Inventory:" << std::endl;
        for (std::vector<Item>::const_iterator it = items.begin(); it != items.end(); ++it) {
            std::cout << "- " << it->name << ": " << it->description << std::endl;
        }
    }

    bool hasItem(const std::string& itemName) const {
        std::string processedItemName = toLower(itemName);
        for (const auto& item : items) {
            if (toLower(item.name) == processedItemName) {
                return true;
            }
        }
        return false;
    }

    Item removeItem(const std::string& itemName) {
        std::string processedItemName = toLower(itemName);
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (toLower(it->name) == processedItemName) {
                Item removedItem = *it;
                items.erase(it);
                return removedItem;
            }
        }
        return Item("", ""); // Return an empty item if not found
    }
};

// RandomEncounter class
class RandomEncounter {
public:
    std::string characterName;
    bool isHostile;
    std::string description;
    std::string triggerItem;

    RandomEncounter(const std::string& name, bool hostile, const std::string& desc, const std::string& item = "")
        : characterName(name), isHostile(hostile), description(desc), triggerItem(item) {}
};



class Wonderland {
private:
    Location* currentLocation;
    Inventory inventory;
    std::map<std::string, Location*> locations;
    Location* safeArea;
    Control control;
    std::vector<Character> characters;
    std::vector<Item> allItems;
    std::vector<RandomEncounter> possibleEncounters;
    int score;
    int moves;
    int maxMoves;
    int health;
    bool isFirstInteraction;

    void loadLocations(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file) {
            throw std::runtime_error("Unable to open file: " + filePath);
        }
        std::string line;
        while (std::getline(file, line) && !line.empty()) {
            try {
                std::istringstream iss(line);
                std::string locName, locDescription, locLongDescription;
                if (!std::getline(iss, locName, ';') || !std::getline(iss, locDescription, ';') || !std::getline(iss, locLongDescription, ';')) {
                    throw std::runtime_error("Invalid format in locations file");
                }
                locations[locName] = new Location(locName, locDescription, locLongDescription);
            } catch (const std::exception& e) {
                std::cerr << "Error processing line: " << line << std::endl;
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }

        // Set locked locations and required items
        if (locations.find("Queen's Garden") != locations.end()) {
            locations["Queen's Garden"]->isLocked = true;
            locations["Queen's Garden"]->requiredItem = "Golden Key";
        }
        if (locations.find("Safe Area") != locations.end()) {
            locations["Safe Area"]->isLocked = true;
            locations["Safe Area"]->requiredItem = "Queen's Crown";
        }
        if (locations.find("Tulgey Wood") != locations.end()) {
            locations["Tulgey Wood"]->isLocked = true;
            locations["Tulgey Wood"]->requiredItem = "Magic Potion";
        }


    }

    void loadItems(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file) {
            throw std::runtime_error("Unable to open file: " + filePath);
        }
        std::string line;
        while (std::getline(file, line) && !line.empty()) {
            std::istringstream iss(line);
            std::string locName, itemName, itemDescription;
            std::getline(iss, locName, ';');
            std::getline(iss, itemName, ';');
            std::getline(iss, itemDescription, ';');
            if (locations.find(locName) != locations.end()) {
                locations[locName]->addItem(Item(itemName, itemDescription));
            }
        }
    }

    void loadCharacters(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file) {
            throw std::runtime_error("Unable to open file: " + filePath);
        }
        std::string line;
        while (std::getline(file, line) && !line.empty()) {
            std::istringstream iss(line);
            std::string locName, charName, charDescription, charCatchphrase, actionsStr;
            std::getline(iss, locName, ';');
            std::getline(iss, charName, ';');
            std::getline(iss, charDescription, ';');
            std::getline(iss, charCatchphrase, ';');
            std::getline(iss, actionsStr, ';');
            
            std::vector<std::string> charActions;
            std::istringstream actionsStream(actionsStr);
            std::string action;
            while (std::getline(actionsStream, action, ',')) {
                charActions.push_back(action);
            }
            
            if (locations.find(locName) != locations.end()) {
                Character newChar(charName, charDescription, charCatchphrase, charActions);
                locations[locName]->addCharacter(newChar);
            }
        }
    }

    void loadActions(const std::string& filePath) {
        control.loadActions(filePath);
    }

    
    void loadExits(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file) {
        throw std::runtime_error("Unable to open file: " + filePath);
        }
        std::string line;
        while (std::getline(file, line) && !line.empty()) {
            std::istringstream iss(line);
            std::string fromLoc, direction, toLoc;
            std::getline(iss, fromLoc, ';');
            std::getline(iss, direction, ';');
            std::getline(iss, toLoc, ';');
            if (locations.find(fromLoc) != locations.end() && locations.find(toLoc) != locations.end()) {
                locations[fromLoc]->exits[direction] = locations[toLoc];
            }
        }
    }

    bool solvePuzzle(const std::string& puzzleName) {
        for (auto& puzzle : currentLocation->puzzles) {
            if (toLower(puzzle.name) == toLower(puzzleName) && !puzzle.solved) {
                std::cout << puzzle.description << std::endl;
                
                while (puzzle.hasAttemptsLeft()) {
                    std::cout << "Attempt " << (puzzle.attempts + 1) << "/" << Puzzle::MAX_ATTEMPTS << std::endl;
                    std::cout << "Enter your solution: ";
                    std::string solution;
                    std::getline(std::cin, solution);
                    
                    if (puzzle.attemptSolve(solution)) {
                        std::cout << "Correct! You solved the puzzle." << std::endl;
                        puzzle.solved = true;
                        return true;
                    } else {
                        std::cout << "Incorrect. ";
                        if (puzzle.hasAttemptsLeft()) {
                            std::cout << "Try again." << std::endl;
                        } else {
                            std::cout << "You've run out of attempts!" << std::endl;
                            return false;
                        }
                    }
                }
                return false; // Puzzle not solved within max attempts
            }
        }
        std::cout << "There is no such unsolved puzzle here." << std::endl;
        return true; // No puzzle found or puzzle already solved
    }

    bool checkWinCondition() {
        return currentLocation == safeArea && 
            inventory.hasItem("Golden Key") && 
            inventory.hasItem("Magic Potion") && 
            inventory.hasItem("Queen's Crown");
    }


    void loadPuzzles(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file) {
            throw std::runtime_error("Unable to open file: " + filePath);
        }
        std::string line;
        while (std::getline(file, line) && !line.empty()) {
            std::istringstream iss(line);
            std::string locName, puzName, puzDescription, puzAnswer;
            std::getline(iss, locName, ';');
            std::getline(iss, puzName, ';');
            std::getline(iss, puzDescription, ';');
            std::getline(iss, puzAnswer, ';');
            if (locations.find(locName) != locations.end()) {
                locations[locName]->addPuzzle(Puzzle(puzName, puzDescription, puzAnswer));
            }
        }
    }

    void showPossibleMoves() const {
        std::cout << "Exits:" << std::endl;
        for (const auto& exit : currentLocation->exits) {
            std::cout << "- " << exit.first << std::endl;
        }
    }


    void handleCombat(const std::string& enemyName, const std::string& description, const std::string& itemReward) {
        std::cout << description << std::endl;
        std::cout << enemyName << " is hostile! You must fight or flee." << std::endl;
        
        int enemyHealth = 50;
        int turnCount = 0;
        int baseDamage = 10;

        while (true) {
            turnCount++;
            std::cout << "\nYour health: " << health << " | " << enemyName << "'s health: " << enemyHealth << std::endl;
            std::cout << "What do you want to do?" << std::endl;
            std::cout << "1. Fight" << std::endl;
            std::cout << "2. Use item" << std::endl;
            std::cout << "3. Defend" << std::endl;
            std::cout << "4. Flee" << std::endl;
            
            std::string choice;
            std::getline(std::cin, choice);
            
            if (toLower(choice) == "fight" || choice == "1") {
                int playerDamage = baseDamage + (health / 10);
                int enemyDamage = baseDamage + (enemyHealth / 10);

                enemyHealth -= playerDamage;
                std::cout << "You deal " << playerDamage << " damage to " << enemyName << "!" << std::endl;

                if (enemyHealth <= 0) {
                    std::cout << "You defeated " << enemyName << "!" << std::endl;
                    int rewardPoints = 50 + (turnCount * 2);
                    incrementScore(rewardPoints);
                    if (!itemReward.empty()) {
                        std::cout << "You found " << itemReward << "!" << std::endl;
                        inventory.addItem(Item(itemReward, "A reward from battle."));
                    }
                    health = std::min(100, health + 10);
                    std::cout << "You regained some health. Current health: " << health << std::endl;
                    return;
                }

                health -= enemyDamage;
                std::cout << enemyName << " deals " << enemyDamage << " damage to you!" << std::endl;

                if (health <= 0) {
                    std::cout << "You were defeated by " << enemyName << "." << std::endl;
                    std::cout << "Game Over!" << std::endl;
                    exit(0);
                }
            } else if (toLower(choice) == "use item" || choice == "2") {
                useItem("", true);
            } else if (toLower(choice) == "defend" || choice == "3") {
                int enemyDamage = (baseDamage + (enemyHealth / 10)) / 2;
                health -= enemyDamage;
                std::cout << "You defend, reducing incoming damage." << std::endl;
                std::cout << enemyName << " deals " << enemyDamage << " damage to you!" << std::endl;
                
                if (health <= 0) {
                    std::cout << "You were defeated by " << enemyName << "." << std::endl;
                    std::cout << "Game Over!" << std::endl;
                    exit(0);
                }
            } else if (toLower(choice) == "flee" || choice == "4") {
                if (turnCount > 3) {
                    std::cout << "You successfully fled from the battle!" << std::endl;
                    health -= 5;
                    std::cout << "You lost 5 health while escaping. Current health: " << health << std::endl;
                    return;
                } else {
                    std::cout << "You failed to escape! It's too early in the battle." << std::endl;
                    health -= 10;
                    std::cout << "You lost 10 health. Current health: " << health << std::endl;
                    if (health <= 0) {
                        std::cout << "You died while trying to escape." << std::endl;
                        std::cout << "Game Over!" << std::endl;
                        exit(0);
                    }
                }
            } else {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }

    void handleFriendlyEncounter(const RandomEncounter& encounter) {
        std::cout << encounter.characterName << " is friendly and offers to help you." << std::endl;
        std::cout << encounter.description << std::endl;
        
        int healthBoost = rand() % 21 + 10; // Random health boost between 10 and 30
        health = std::min(100, health + healthBoost);
        
        std::cout << "They heal some of your health." << std::endl;
        std::cout << "You gained " << healthBoost << " health. Your health is now " << health << std::endl;
        
        // Possibility of receiving an item
        if (rand() % 4 == 0) { // 25% chance
            std::string items[] = {"Health Potion", "Magic Scroll", "Lucky Charm"};
            std::string givenItem = items[rand() % 3];
            std::cout << encounter.characterName << " gives you a " << givenItem << "!" << std::endl;
            inventory.addItem(Item(givenItem, "A gift from a friendly encounter."));
        }
        
        incrementScore(20); // Reward for friendly encounter
    }

    void loadEncounters(const std::string& filePath) {
        std::ifstream file(filePath);
            if (!file) {
                throw std::runtime_error("Unable to open file: " + filePath);
            }
        std::string line;
        while (std::getline(file, line) && !line.empty()) {
            std::istringstream iss(line);
            std::string name, isHostile, description, triggerItem;
            std::getline(iss, name, ';');
            std::getline(iss, isHostile, ';');
            std::getline(iss, description, ';');
            std::getline(iss, triggerItem, ';');
            possibleEncounters.push_back(RandomEncounter(name, isHostile == "true", description, triggerItem));
        }
    }

    
public:
    Wonderland(const std::string& locationsFile, const std::string& itemsFile, 
               const std::string& charactersFile, const std::string& exitsFile, 
               const std::string& puzzlesFile, const std::string& actionsFile,
               const std::string& encountersFile) {

        score = 0;
        moves = 0;
        maxMoves = 100;
        health = 100;
        isFirstInteraction = true;
        loadLocations(locationsFile);
        loadItems(itemsFile);
        loadCharacters(charactersFile);
        loadExits(exitsFile);
        loadPuzzles(puzzlesFile);
        loadActions(actionsFile);
        loadEncounters(encountersFile);

        if (locations.find("Above Ground") != locations.end()) {
            currentLocation = locations["Above Ground"];
        } else {
            throw std::runtime_error("Initial location 'Above Ground' not found");
        }

        if (locations.find("Safe Area") != locations.end()) {
            safeArea = locations["Safe Area"];
        } else {   
            throw std::runtime_error("Safe area location 'Safe Area' not found");
        }
    }

    ~Wonderland() {
        for (auto& pair : locations) {
            delete pair.second;
        }
    }

    void play() {
        std::string input;
        while (true) {
            std::cout << "\n";
            currentLocation->showDetails();
            showPossibleMoves();
            std::cout << "\nMoves: " << moves << "/" << maxMoves << " | Health: " << health << " | Score: " << score << "\n" << std::endl;

            if (!isFirstInteraction) {
                generateRandomEncounter();
            }
            isFirstInteraction = false;
            
            std::cout << "\nWhat do you want to do? ";
            std::getline(std::cin, input);

            std::pair<std::string, std::string> parsedInput = control.parseInput(input);
            std::string action = parsedInput.first;
            std::string object = parsedInput.second;
            
            if (action == "quit") {
                std::cout << "Thank you for playing! Your final score is: " << score << std::endl;
                break;
            }

            std::cout << "\n";
            if (action == "solve") {
                if (!solvePuzzle(object)) {
                    std::cout << "Game over! You failed to solve the puzzle in " << Puzzle::MAX_ATTEMPTS << " attempts." << std::endl;
                    std::cout << "Your final score is: " << score << std::endl;
                    break;
                }
            } else {
                executeAction(action, object);
            }

            if (checkWinCondition()) {
                std::cout << "Congratulations! You have won the game!" << std::endl;
                std::cout << "Your final score is: " << score << std::endl;
                break;
            }

            if (checkLoseCondition()) {
                std::cout << "Your final score is: " << score << std::endl;
                break;
            }
        }
    }

    bool checkLoseCondition() {
        if (moves >= maxMoves) {
            std::cout << "You've run out of moves! Game over." << std::endl;
            return true;
        }
        if (health <= 0) {
            std::cout << "Your health has reached zero! Game over." << std::endl;
            return true;
        }
        if (currentLocation->name == "Queen's Garden" && !inventory.hasItem("Magic Potion")) {
            std::cout << "The Queen of Hearts caught you without protection! Off with your head! Game over." << std::endl;
            return true;
        }
        return false;
    }

    void executeAction(const std::string& action, const std::string& object) {
        std::string lowerAction = toLower(action);
        std::string lowerObject = toLower(object);

        if (lowerAction.empty()) {
            std::cout << "Please enter a valid action." << std::endl;
            return;
        }

        if (lowerAction == "go" || lowerAction == "move") {
            if (lowerObject.empty()) {
                std::cout << "Please specify a direction to go." << std::endl;
            } else {
                move(lowerObject);
            }
        } else if (lowerAction == "take") {
            if (lowerObject.empty()) {
                std::cout << "Please specify an item to take." << std::endl;
            } else {
                takeItem(lowerObject);
            }
        } else if (lowerAction == "use") {
            if (lowerObject.empty()) {
                std::cout << "Please specify an item to use." << std::endl;
            } else {
                useItem(lowerObject);
            }
        } else if (lowerAction == "look") {
            look();
        } else if (lowerAction == "inventory") {
            inventory.showInventory();
        } else if (lowerAction == "talk") {
            if (lowerObject.empty()) {
                std::cout << "Please specify a character to talk to." << std::endl;
            } else {
                talkToCharacter(lowerObject);
            }
        } else if (lowerAction == "solve") {
            if (lowerObject.empty()) {
                std::cout << "Please specify a puzzle to solve." << std::endl;
            } else {
                solvePuzzle(lowerObject);
            }
        } else {
            std::cout << "I don't understand that command." << std::endl;
        }
    }


    void move(const std::string& direction) {
        auto it = currentLocation->exits.find(toLower(direction));
        if (it != currentLocation->exits.end() && it->second != nullptr) {
            if (it->second->isLocked) {
                std::cout << "The path to " << it->second->name << " is locked. You need to find a way to unlock it." << std::endl;
            } else {
                Location* previousLocation = currentLocation;
                currentLocation = it->second;
                std::cout << "You move " << direction << " to " << currentLocation->name << "." << std::endl;
                if (currentLocation->firstVisit) {
                    std::cout << "As you enter for the first time, you take in the surroundings..." << std::endl;
                }
                moves++;
                health -= 5; // Moving consumes health
                std::cout << "The journey has tired you a bit. Your health is now " << health << std::endl;
            }
        } else {
            std::cout << "The path is locked. You need to use an item to unlock it." << std::endl;
        }
    }

    void takeItem(const std::string& itemName) {
        bool itemExists = false;
        std::string actualItemName;

        // Find the actual item name with correct capitalization
        for (const auto& item : currentLocation->items) {
            if (toLower(item.name) == toLower(itemName)) {
                itemExists = true;
                actualItemName = item.name;
                break;
            }
        }

        if (!itemExists) {
            std::cout << "There is no " << itemName << " here." << std::endl;
            return;
        }

        for (auto& puzzle : currentLocation->puzzles) {
            if (toLower(puzzle.name).find(toLower(actualItemName)) != std::string::npos && !puzzle.solved) {
                std::cout << "To take the " << actualItemName << ", you need to solve a puzzle first." << std::endl;
                if (!solvePuzzle(puzzle.name)) {
                    std::cout << "You failed to solve the puzzle. You can't take the " << actualItemName << " yet." << std::endl;
                    return;
                }
                std::cout << "Puzzle solved! You can now take the " << actualItemName << "." << std::endl;
                break;
            }
        }
        
        bool itemTaken;
        Item item = currentLocation->takeItem(itemName, itemTaken);
        if (itemTaken) {
            inventory.addItem(item);
            std::cout << "You took the " << item.name << "." << std::endl;
            incrementScore(10);
        } else {
            std::cout << "There was an error taking the " << actualItemName << "." << std::endl;
        }
    }

    void useItem(const std::string& itemName, bool inCombat = false) {
        std::string processedItemName = toLower(itemName);
        if (inventory.hasItem(processedItemName)) {
            if (processedItemName == toLower("Golden Key")) {
                if (inCombat) {
                    std::cout << "The Golden Key has no effect in combat." << std::endl;
                } else {
                    auto it = currentLocation->exits.find("east");
                    if (it != currentLocation->exits.end() && toLower(it->second->name) == toLower("Queen's Garden") && it->second->isLocked) {
                        it->second->isLocked = false;
                        std::cout << "You used the Golden Key to unlock the path to the Queen's Garden." << std::endl;
                    } else {
                        std::cout << "There's nothing to unlock here with the Golden Key." << std::endl;
                    }
                }
            } else if (itemName == "Queen's Crown") {
                if (inCombat) {
                    std::cout << "The Queen's Crown intimidates your enemy!" << std::endl;
                    // Note: We can't modify enemy health here as it's not accessible
                    std::cout << "The enemy seems weakened!" << std::endl;
                } else {
                    auto it = currentLocation->exits.find("north");
                    if (it != currentLocation->exits.end() && it->second->name == "Safe Area" && it->second->isLocked) {
                        it->second->isLocked = false;
                        std::cout << "You used the Queen's Crown to unlock the path to the Safe Area." << std::endl;
                    } else {
                        std::cout << "There's no use for the Queen's Crown here." << std::endl;
                    }
                }
            } else if (itemName == "Magic Wand") {
                std::cout << "You use the Magic Wand! It casts a powerful spell." << std::endl;
                if (inCombat) {
                    std::cout << "The enemy takes significant damage!" << std::endl;
                } else {
                    health = std::min(100, health + 30);
                    std::cout << "You gained 30 health. Current health: " << health << std::endl;
                }
                inventory.removeItem(itemName);
            } else if (itemName == "Magic Berry") {
                std::cout << "You eat the Magic Berry. You feel slightly better." << std::endl;
                health = std::min(100, health + 20);
                std::cout << "You gained 20 health. Current health: " << health << std::endl;
                inventory.removeItem(itemName);
            } else {
                std::cout << "You use the " << itemName << ", but nothing special happens." << std::endl;
            }
        } else {
            std::cout << "You don't have that item." << std::endl;
        }
    }


    void look() {
        currentLocation->showDetails();
    }

    void talkToCharacter(const std::string& characterName) {
        bool characterFound = false;
        for (const auto& character : currentLocation->characters) {
            if (toLower(character.name) == toLower(characterName)) {
                characterFound = true;
                character.speak();
                character.performAction();
                break;
            }
        }
        if (!characterFound) {
            std::cout << "There is no character named " << characterName << " here." << std::endl;
        }
    }

    void printInstructions() const {
        std::cout << "Welcome to the Wonderland Adventure Game!\n";
        std::cout << "Here are some commands you can use:\n";
        std::cout << "- go (move) <direction>: Move in a direction (e.g., north, south, east, west, up, down).\n";
        std::cout << "- take <item>: Take an item from the current location.\n";
        std::cout << "- use <item>: Use an item from your inventory.\n";
        std::cout << "- talk <character>: Talk to a character in the current location.\n";
        std::cout << "- look: Look around the current location.\n";
        std::cout << "- inventory: Show your current inventory.\n";
        std::cout << "- solve <puzzle>: Attempt to solve a puzzle in the current location.\n";
        std::cout << "- quit: Quit the game.\n";
        std::cout << "You are Alice. Your goal is to collect the Golden Key, the Magic Potion, and the Queen's Crown, and then reach the Safe Area to win the game.\n";
        std::cout << "Be prepared to face challenges while collecting the items. \n";
        std::cout << "Use your wits to solve puzzles and overcome the obstacles.\n Also be careful in combat! If you're defeated, it's game over.\n";
        std::cout << "Have fun exploring Wonderland!\n";
    }

    void incrementScore(int points) {
    score += points;
    std::cout << "You gained " << points << " points!" << std::endl;
    std::cout << "Your current score is: " << score << std::endl;
    }

    void generateRandomEncounter() {
        if (rand() % 100 < 24 && !possibleEncounters.empty()) { // 20% chance of encounter
            RandomEncounter encounter = possibleEncounters[rand() % possibleEncounters.size()];
            
            if (encounter.isHostile) {
                handleCombat(encounter.characterName, encounter.description, encounter.triggerItem);
            } else {
                handleFriendlyEncounter(encounter);
            }
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    try {
        Wonderland game("locations.txt", "items.txt", "characters.txt", "exits.txt", "puzzles.txt", "actions.txt", "encounters.txt");
        game.printInstructions();
        game.play();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}