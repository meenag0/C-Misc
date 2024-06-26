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

    Item(const std::string& itemName, const std::string& itemDescription) : name(itemName), description(itemDescription) {}
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

class Location {
public:
    std::string name;
    std::string description;
    std::map<std::string, Location*> exits;
    std::vector<Item> items;
    std::vector<Character> characters;

    Location(const std::string& locName, const std::string& locDescription) : name(locName), description(locDescription) {}

    void addItem(const Item& item) {
        items.push_back(item);
    }

    void addCharacter(const Character& character) {
        characters.push_back(character);
    }

    void showDetails() const {
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

    Item takeItem(const std::string& itemName, bool& itemTaken) {
        auto it = std::find_if(items.begin(), items.end(), [&itemName](const Item& item) {
            return item.name == itemName;
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
};

class Inventory {
public:
    std::vector<Item> items;

    void addItem(const Item& item) {
        items.push_back(item);
    }

    bool hasItem(const std::string& itemName) const {
        return std::any_of(items.begin(), items.end(), [&itemName](const Item& item) {
            return item.name == itemName;
        });
    }

    void showInventory() const {
        std::cout << "Inventory:" << std::endl;
        for (const auto& item : items) {
            std::cout << "- " << item.name << ": " << item.description << std::endl;
        }
    }
};

class Game {
private:
    Location* currentLocation;
    Inventory inventory;
    std::map<std::string, Location*> locations;
    Location* safeArea;

    void loadLocations(std::ifstream& file) {
        std::string line;
        while (std::getline(file, line) && !line.empty()) {
            std::istringstream iss(line);
            std::string locName, locDescription;
            std::getline(iss, locName, ';');
            std::getline(iss, locDescription, ';');
            locations[locName] = new Location(locName, locDescription);
            std::cout << "Loaded location: " << locName << std::endl;  // Debugging output
        }
    }

    void loadItems(std::ifstream& file) {
        std::string line;
        while (std::getline(file, line) && !line.empty()) {
            std::istringstream iss(line);
            std::string locName, itemName, itemDescription;
            std::getline(iss, locName, ';');
            std::getline(iss, itemName, ';');
            std::getline(iss, itemDescription, ';');
            if (locations.find(locName) != locations.end()) {
                locations[locName]->addItem(Item(itemName, itemDescription));
                std::cout << "Loaded item: " << itemName << " in " << locName << std::endl;  // Debugging output
            }
        }
    }

    void loadCharacters(std::ifstream& file) {
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
                locations[locName]->addCharacter(Character(charName, charDescription, charCatchphrase, charActions));
                std::cout << "Loaded character: " << charName << " in " << locName << std::endl;  // Debugging output
            }
        }
    }

    void loadExits(std::ifstream& file) {
        std::string line;
        while (std::getline(file, line) && !line.empty()) {
            std::istringstream iss(line);
            std::string fromLoc, direction, toLoc;
            std::getline(iss, fromLoc, ';');
            std::getline(iss, direction, ';');
            std::getline(iss, toLoc, ';');
            if (locations.find(fromLoc) != locations.end() && locations.find(toLoc) != locations.end()) {
                locations[fromLoc]->exits[direction] = locations[toLoc];
                std::cout << "Loaded exit: " << fromLoc << " to " << toLoc << " via " << direction << std::endl;  // Debugging output
            }
        }
    }

public:
    Game(const std::string& dataFilePath) {
        std::ifstream file(dataFilePath);
        if (!file) {
            throw std::runtime_error("Unable to open file");
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line == "[Locations]") {
                loadLocations(file);
            } else if (line == "[Items]") {
                loadItems(file);
            } else if (line == "[Characters]") {
                loadCharacters(file);
            } else if (line == "[Exits]") {
                loadExits(file);
            }
        }

        currentLocation = locations["Above Ground"];
        safeArea = locations["Safe Area"];
    }

    ~Game() {
        for (auto& pair : locations) {
            delete pair.second;
        }
    }

    void printInstructions() const {
        std::cout << "Welcome to the Wonderland Adventure Game!\n";
        std::cout << "Here are some commands you can use:\n";
        std::cout << "- move (m) <direction>: Move in a direction (e.g., north, south, east, west, up, down).\n";
        std::cout << "- take (t) <item>: Take an item from the current location.\n";
        std::cout << "- talk (k) <character>: Talk to a character in the current location.\n";
        std::cout << "- inventory (i): Show your current inventory.\n";
        std::cout << "- look (l): Look around the current location.\n";
        std::cout << "- quit (q): Quit the game.\n";
        std::cout << "Your goal is to collect the Golden Key, the Magic Potion, and the Queen's Crown, and then reach the Safe Area to win the game.\n";
        std::cout << "Be prepared to face challenges while collecting the items.\n";
        std::cout << "Have fun exploring Wonderland!\n";
    }

    void play() {
        std::string command;
        while (true) {
            std::cout << "\nCurrent location: " << currentLocation->name << std::endl;
            currentLocation->showDetails();
            std::cout << "\nWhat do you want to do? ";
            std::getline(std::cin, command);

            // Convert command to lower case for case insensitivity
            std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c) {
                return std::tolower(c); // Correct the lambda syntax by adding this line break
            });
            if (command == "quit" || command == "q") {
                std::cout << "Thank you for playing! Goodbye." << std::endl;
                break;
            } else if (command == "inventory" || command == "i") {
                inventory.showInventory();
            } else if (command == "look" || command == "l") {
                currentLocation->showDetails();
            } else if (command.substr(0, 5) == "take " || command.substr(0, 2) == "t ") {
                std::string itemName = (command[0] == 't') ? command.substr(2) : command.substr(5);
                bool itemTaken;
                if (challengePassed(itemName)) {
                    Item item = currentLocation->takeItem(itemName, itemTaken);
                    if (itemTaken) {
                        inventory.addItem(item);
                        std::cout << "You took the " << item.name << "." << std::endl;
                    } else {
                        std::cout << "There is no such item here." << std::endl;
                    }
                }
            } else if (command.substr(0, 5) == "talk " || command.substr(0, 2) == "k ") {
                std::string charName = (command[0] == 'k') ? command.substr(2) : command.substr(5);
                bool characterFound = false;
                for (const auto& character : currentLocation->characters) {
                    if (character.name == charName) {
                        character.speak();
                        character.performAction();
                        characterFound = true;
                        break;
                    }
                }
                if (!characterFound) {
                    std::cout << "There is no such character here." << std::endl;
                }
            } else if (command.substr(0, 5) == "move " || command.substr(0, 2) == "m ") {
                std::string direction = (command[0] == 'm') ? command.substr(2) : command.substr(5);
                auto it = currentLocation->exits.find(direction);
                if (it != currentLocation->exits.end()) {
                    currentLocation = it->second;
                    std::cout << "You move " << direction << " to " << currentLocation->name << "." << std::endl;

                    // Check if the player has reached the safe area with all items
                    if (currentLocation == safeArea && checkWinCondition()) {
                        std::cout << "Congratulations! You have collected all the necessary items and reached the Safe Area. You win the game!" << std::endl;
                        break;
                    } else if (currentLocation == safeArea) {
                        std::cout << "You have reached the Safe Area, but you do not have all the necessary items. Keep exploring!" << std::endl;
                    }
                } else {
                    std::cout << "You can't go that way." << std::endl;
                }
            } else {
                std::cout << "Unknown command. Please try again." << std::endl;
                printInstructions();
            }
        }
    }

private:
    bool checkWinCondition() const {
        return inventory.hasItem("Golden Key") && inventory.hasItem("Magic Potion") && inventory.hasItem("Queen's Crown");
    }

    bool challengePassed(const std::string& itemName) const {
        if (itemName == "golden key") {
            std::cout << "The White Rabbit stops you and asks you to answer a riddle to get the Golden Key." << std::endl;
            std::cout << "Riddle: What has keys but can't open locks?" << std::endl;
            std::string answer;
            std::getline(std::cin, answer);
            std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
            if (answer == "piano" || answer == "a piano") {
                std::cout << "Correct! The White Rabbit gives you the Golden Key." << std::endl;
                return true;
            } else {
                std::cout << "Incorrect! You cannot take the Golden Key." << std::endl;
                return false;
            }
        } else if (itemName == "magic potion") {
            std::cout << "The Cheshire Cat appears and says you must find a hidden item first." << std::endl;
            if (inventory.hasItem("hidden mushroom")) {
                std::cout << "You already have the Hidden Mushroom! The Cheshire Cat lets you take the Magic Potion." << std::endl;
                return true;
            } else {
                std::cout << "You don't have the Hidden Mushroom. The Cheshire Cat prevents you from taking the Magic Potion." << std::endl;
                return false;
            }
        } else if (itemName == "queen's crown") {
            std::cout << "The Queen of Hearts challenges you to a game of croquet. You must win to take the Queen's Crown." << std::endl;
            std::cout << "Choose: rock, paper, or scissors." << std::endl;
            std::string playerChoice;
            std::getline(std::cin, playerChoice);
            std::transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), ::tolower);

            std::vector<std::string> choices = {"rock", "paper", "scissors"};
            std::string queenChoice = choices[rand() % choices.size()];
            std::cout << "The Queen of Hearts chose: " << queenChoice << std::endl;

            if ((playerChoice == "rock" && queenChoice == "scissors") ||
                (playerChoice == "paper" && queenChoice == "rock") ||
                (playerChoice == "scissors" && queenChoice == "paper")) {
                std::cout << "You win! You can take the Queen's Crown." << std::endl;
                return true;
            } else if (playerChoice == queenChoice) {
                std::cout << "It's a draw! You must try again." << std::endl;
                return false;
            } else {
                std::cout << "You lose! You cannot take the Queen's Crown." << std::endl;
                return false;
            }
        }
        return true;
    }
};

int main() {
    try {
        Game game("game_data.txt");
        game.printInstructions();
        game.play();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
