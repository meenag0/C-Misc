#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include <cctype>

class Item {
public:
    std::string name;
    std::string description;

    Item(const std::string& itemName, const std::string& itemDescription) 
        : name(itemName), description(itemDescription) {}
};

class Character {
public:
    std::string name;
    std::string description;
    std::string catchphrase;
    std::vector<std::string> actions;


    Character(const std::string& charName, const std::string& charDescription, const std::string& charCatchphrase, const std::vector<std::string>& charActions)
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


class Location {
public:
    std::string name;
    std::string description;
    std::map<std::string, Location*> exits;
    std::vector<Item> items;
    std::vector<Character> characters;
    std::vector<Puzzle> puzzles;
    mutable bool firstVisit;

     Location(const std::string& locName, const std::string& locDescription) 
        : name(locName), description(locDescription), firstVisit(true) {}  // Update this line


    void addItem(const Item& item) {
        items.push_back(item);
    }

    void addCharacter(const Character& character) {
        characters.push_back(character);
    }

    void addPuzzle(const Puzzle& puzzle) {
        puzzles.push_back(puzzle);
    }

    void showDetails() const {
        if (firstVisit) {
            std::cout << "You are visiting " << name << " for the first time." << std::endl;
            firstVisit = false;  // Set to false after first visit
        }
        std::cout << description << std::endl;

        if (!items.empty()) {
            std::cout << "You see:" << std::endl;
            for (const auto& item : items) {
                std::cout << "- " << item.name << ": " << item.description << std::endl;
            }
        }
        if (!characters.empty()) {
            std::cout << "Characters here:" << std::endl;
            for (const auto& character : characters) {
                std::cout << "- " << character.name << ": " << character.description << std::endl;
            }
        }
    }

    bool isLocked;
    std::string requiredItem;

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

    

    class ItemNameMatcher {
    public:
        explicit ItemNameMatcher(const std::string& name) : name_(toLower(name)) {}
        bool operator()(const Item& item) const { return toLower(item.name) == name_; }
    private:
        std::string name_;
        static std::string toLower(std::string s) {
            std::transform(s.begin(), s.end(), s.begin(), 
                        [](unsigned char c){ return std::tolower(c); });
            return s;
        }
    };

    Item takeItem(const std::string& itemName, bool& itemTaken) {
        auto it = std::find_if(items.begin(), items.end(), ItemNameMatcher(itemName));
        if (it != items.end()) {
            Item item = *it;
            items.erase(it);
            itemTaken = true;
            return item;
        }
        itemTaken = false;
        return Item("", "");
    }
};

class Inventory {
private:
    static std::string toLower(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), 
            [](unsigned char c){ return std::tolower(c); });
        return s;
    }

public:
    std::vector<Item> items;

    void addItem(const Item& item) {
        items.push_back(item);
    }

    void showInventory() const {
        std::cout << "Inventory:" << std::endl;
        for (const auto& item : items) {
            std::cout << "- " << item.name << ": " << item.description << std::endl;
        }
    }

    bool hasItem(const std::string& itemName) const {
        return std::any_of(items.begin(), items.end(), 
            [&](const Item& item) { return toLower(item.name) == toLower(itemName); });
    }

    bool removeItem(const std::string& itemName) {
        auto it = std::find_if(items.begin(), items.end(),
            [&](const Item& item) { return toLower(item.name) == toLower(itemName); });
        if (it != items.end()) {
            items.erase(it);
            return true;
        }
        return false;
    }
};


class Actions {
private:
    std::map<std::string, std::vector<std::string>> actionSynonyms;
    std::map<std::string, std::string> directionShortcuts;

public:
    Actions() {
        // Initialize with some basic actions and their synonyms
        actionSynonyms["go"] = {"move", "walk", "travel", "g"};
        actionSynonyms["take"] = {"pick", "grab", "get", "t"};
        actionSynonyms["use"] = {"utilize", "employ", "u"};
        actionSynonyms["look"] = {"examine", "inspect", "l"};
        actionSynonyms["inventory"] = {"items", "i"};
        actionSynonyms["quit"] = {"exit", "q"};
        actionSynonyms["throw"] = {"toss", "hurl"};

        // Initialize direction shortcuts
        directionShortcuts["n"] = "north";
        directionShortcuts["s"] = "south";
        directionShortcuts["e"] = "east";
        directionShortcuts["w"] = "west";
        directionShortcuts["u"] = "up";
        directionShortcuts["d"] = "down";
    }

    void loadFromFile(const std::string& filePath) {
        std::ifstream file(filePath);
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
        for (const auto& pair : actionSynonyms) {
            if (input == pair.first || std::find(pair.second.begin(), pair.second.end(), input) != pair.second.end()) {
                return pair.first;
            }
        }
        return input; // If no synonym found, return the original input
    }

    std::string expandDirection(const std::string& input) const {
        auto it = directionShortcuts.find(input);
        if (it != directionShortcuts.end()) {
            return it->second;
        }
        return input;
    }

private:
    static std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        if (std::string::npos == first) {
            return str;
        }
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }
};

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
        std::string baseAction = actions.getBaseAction(action);

        return std::make_pair(baseAction, object);
    }
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
    int score;
    int moves;
    int maxMoves;
    int health;


    void loadLocations(const std::string& filePath) {
        std::ifstream file(filePath);
        std::string line;
        while (std::getline(file, line) && !line.empty()) {
            std::istringstream iss(line);
            std::string locName, locDescription;
            std::getline(iss, locName, ';');
            std::getline(iss, locDescription, ';');
            locations[locName] = new Location(locName, locDescription);
        // The firstVisit flag is automatically set to true in the constructor
        }
        locations["Queen's Garden"]->isLocked = true;
        locations["Queen's Garden"]->requiredItem = "Golden Key";

        locations["Safe Area"]->isLocked = true;
        locations["Safe Area"]->requiredItem = "Queen's Crown";
        
        locations["Tulgey Wood"]->isLocked = true;
        locations["Tulgey Wood"]->requiredItem = "Magic Potion";

    }

    void loadItems(const std::string& filePath) {
        std::ifstream file(filePath);
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
            if (puzzle.name == puzzleName && !puzzle.solved) {
                std::cout << puzzle.description << std::endl;
                
                while (puzzle.hasAttemptsLeft()) {
                    std::cout << "Attempt " << (puzzle.attempts + 1) << "/" << Puzzle::MAX_ATTEMPTS << std::endl;
                    std::cout << "Enter your solution: ";
                    std::string solution;
                    std::getline(std::cin, solution);
                    
                    if (puzzle.attemptSolve(solution)) {
                        std::cout << "Correct! You solved the puzzle." << std::endl;
                        incrementScore(25); // Award points for solving a puzzle
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

    bool checkWinCondition() const {
        return inventory.hasItem("golden key") && inventory.hasItem("magic potion") && inventory.hasItem("queen's crown");
    }

    void loadPuzzles(const std::string& filePath) {
        std::ifstream file(filePath);
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
            std::cout << "- " << exit.first << " (to " << exit.second->name << ")" << std::endl;
        }
    }

    static std::string toLower(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), 
        [](unsigned char c){ return std::tolower(c); });
        return s;
    }

 
    void useGoldenKey() {
        auto it = currentLocation->exits.find("east");
        if (it != currentLocation->exits.end() && it->second->name == "Queen's Garden" && it->second->isLocked) {
            it->second->isLocked = false;
            std::cout << "You used the Golden Key to unlock the path to the Queen's Garden." << std::endl;
        } else {
            std::cout << "There's nothing to unlock here with the Golden Key." << std::endl;
        }
    }

    void useMagicPotion() {
        auto it = currentLocation->exits.find("north");
        if (it != currentLocation->exits.end() && it->second->name == "Tulgey Wood" && it->second->isLocked) {
            it->second->isLocked = false;
            std::cout << "You drink the Magic Potion. You feel your size changing!" << std::endl;
            std::cout << "This allows you to access the Tulgey Wood." << std::endl;
            inventory.removeItem("Magic Potion");
        } else {
            std::cout << "You drink the Magic Potion, but nothing special happens here." << std::endl;
            inventory.removeItem("Magic Potion");
        }
    }

    void useQueensCrown() {
        auto it = currentLocation->exits.find("north");
        if (it != currentLocation->exits.end() && it->second->name == "Safe Area" && it->second->isLocked) {
            it->second->isLocked = false;
            std::cout << "You used the Queen's Crown to unlock the path to the Safe Area." << std::endl;
        } else {
            std::cout << "There's no use for the Queen's Crown here." << std::endl;
        }
    }


public:
    Wonderland(const std::string& locationsFile, const std::string& itemsFile, 
               const std::string& charactersFile, const std::string& exitsFile, 
               const std::string& puzzlesFile, const std::string& actionsFile) {

        score = 0;
        moves = 0;
        maxMoves = 100;
        health = 100;
        loadLocations(locationsFile);
        loadItems(itemsFile);
        loadCharacters(charactersFile);
        loadExits(exitsFile);
        loadPuzzles(puzzlesFile);
        loadActions(actionsFile);

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
        displayIntro();
        std::string input;
        while (true) {
            std::cout << "\nCurrent location: " << currentLocation->name << std::endl;
            currentLocation->showDetails();
            showPossibleMoves();
            std::cout << "\nMoves: " << moves << "/" << maxMoves << " | Health: " << health << " | Score: " << score << std::endl;
            std::cout << "\nWhat do you want to do? ";
            std::getline(std::cin, input);

            std::pair<std::string, std::string> parsedInput = control.parseInput(input);
            std::string action = parsedInput.first;
            std::string object = parsedInput.second;
            
            if (action == "quit") {
                std::cout << "Thank you for playing! Your final score is: " << score << std::endl;
                break;
            }

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

    void displayIntro() {
        std::cout << "Welcome to Wonderland!\n";
        std::cout << "You are Alice, and your goal is to collect the Golden Key, the Magic Potion, and the Queen's Crown,\n";
        std::cout << "then return to the Safe Area to win the game.\n";
        std::cout << "Be careful of the characters you meet along the way, and use your wits to solve puzzles and overcome obstacles.\n";
        std::cout << "Good luck on your adventure!\n\n";
    }

    bool checkWinCondition() {
        return currentLocation == safeArea && 
               inventory.hasItem("Golden Key") && 
               inventory.hasItem("Magic Potion") && 
               inventory.hasItem("Queen's Crown");
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
        if (action == "go" || action == "move") {
            move(object);
        } else if (action == "take") {
            takeItem(object);
        } else if (action == "use") {
            useItem(object);
        } else if (action == "look") {
            look();
        } else if (action == "inventory") {
            inventory.showInventory();
        } else if (action == "talk") {
            talkToCharacter(object);
        } else if (action == "solve") {
            solvePuzzle(object);
        } else {
            std::cout << "I don't understand that command." << std::endl;
        }
    }

    void move(const std::string& direction) {
        auto it = currentLocation->exits.find(direction);
        if (it != currentLocation->exits.end() && it->second != nullptr) {
            if (it->second->isLocked) {
            } else {
                currentLocation = it->second;
                std::cout << "You move " << direction << " to " << currentLocation->name << "." << std::endl;
                moves++;
                health -= 5; // Moving consumes health
                std::cout << "Your health is now " << health << std::endl;
            }
        } else {
            std::cout << "You can't go that way." << std::endl;
        }
    }

    void takeItem(const std::string& itemName) {
        // First, check if the item exists in the current location
        bool itemExists = false;
        for (const auto& item : currentLocation->items) {
            if (toLower(item.name) == toLower(itemName)) {
                itemExists = true;
                break;
            }
        }

        if (!itemExists) {
            std::cout << "There is no " << itemName << " here." << std::endl;
            return;
        }

        // Check if there's a related puzzle that needs to be solved
        for (auto& puzzle : currentLocation->puzzles) {
            if (toLower(puzzle.name).find(toLower(itemName)) != std::string::npos && !puzzle.solved) {
                std::cout << "To take the " << itemName << ", you need to solve a puzzle first." << std::endl;
                if (!solvePuzzle(puzzle.name)) {
                    std::cout << "You failed to solve the puzzle. You can't take the " << itemName << " yet." << std::endl;
                    return;
                }
                std::cout << "Puzzle solved! You can now take the " << itemName << "." << std::endl;
                break;
            }
        }
        
        // If we've reached here, either there was no puzzle or the puzzle was solved
        bool itemTaken;
        Item item = currentLocation->takeItem(itemName, itemTaken);
        if (itemTaken) {
            inventory.addItem(item);
            std::cout << "You took the " << item.name << "." << std::endl;
            incrementScore(10);
        } else {
            std::cout << "There was an error taking the " << itemName << "." << std::endl;
        }
    }

    void useItem(const std::string& itemName) {
        if (inventory.hasItem(itemName)) {
            if (itemName == "Golden Key") {
                useGoldenKey();
            } else if (itemName == "Magic Potion") {
                useMagicPotion();
            } else if (itemName == "Queen's Crown") {
                useQueensCrown();
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
        std::cout << "Your goal is to collect the Golden Key, the Magic Potion, and the Queen's Crown, and then reach the Safe Area to win the game.\n";
        std::cout << "Be prepared to face challenges while collecting the items.\n";
        std::cout << "Have fun exploring Wonderland!\n";
    }

    void incrementScore(int points) {
    score += points;
    std::cout << "You gained " << points << " points!" << std::endl;
    std::cout << "Your current score is: " << score << std::endl;
    }

};

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    try {
        Wonderland game("locations.txt", "items.txt", "characters.txt", "exits.txt", "puzzles.txt", "actions.txt");
        game.printInstructions();
        game.play();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}