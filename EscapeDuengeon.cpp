#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// Global Variables
vector<string> inventory;
int health = 100;

// Functions Declarations
void displayInventory() {
    cout << "Your Inventory: ";
    if (inventory.empty()) {
        cout << "empty\n";
    } else {
        for (const string& item : inventory) {
            cout << item << " ";
        }
        cout << endl;
    }
}
void saveGame()
{
    ofstream file("savegame.txt");
    if (file.is_open())
    {
        file << health << endl;
        for (const string &item : inventory)
        {
            file << item << endl;
        }
        file.close();
        cout << "Game saved!\n";
    }
    else
    {
        cout << "Failed to save game.\n";
    }
}

void loadGame()
{
    ifstream file("savegame.txt");
    if (file.is_open())
    {
        inventory.clear();
        file >> health;
        string item;
        while (file >> item)
        {
            inventory.push_back(item);
        }
        file.close();
        cout << "Game loaded! Health: " << health << ", Inventory: ";
        displayInventory();
    }
    else
    {
        cout << "No save file found. Starting a new game.\n";
    }
}

void loadGame();
void navigateRoom(int roomNumber)
{
    cout << "\nYou enter Room " << roomNumber << ".\n";

    if (roomNumber == 1)
    {
        cout << "You see a locked door and a table with a key on it.\n";
        cout << "1. Pick up the key.\n";
        cout << "2. Leave the room.\n";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            inventory.push_back("Key");
            cout << "You picked up a key!\n";
        }
        else
        {
            cout << "You leave the room empty-handed.\n";
        }
    }
    else if (roomNumber == 2)
    {
        cout << "An enemy blocks your path!\n";
        combat();
    }
    else if (roomNumber == 3)
    {
        cout << "You find a treasure chest.\n";
        cout << "1. Open it.\n";
        cout << "2. Ignore it.\n";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            inventory.push_back("Treasure");
            cout << "You found a hidden treasure!\n";
        }
        else
        {
            cout << "You leave the treasure behind.\n";
        }
    }
}

void combat()
{
    int enemyHealth = 50;

    while (enemyHealth > 0 && health > 0)
    {
        cout << "Your Health: " << health << ", Enemy Health: " << enemyHealth << endl;
        cout << "1. Attack\n";
        cout << "2. Defend\n";
        int choice;
        cin >> choice;

        int playerDamage = rand() % 15 + 5; // Random damage between 5 and 20
        int enemyDamage = rand() % 15 + 5;

        if (choice == 1)
        {
            enemyHealth -= playerDamage;
            cout << "You attack the enemy for " << playerDamage << " damage!\n";
        }
        else
        {
            enemyDamage /= 2;
            cout << "You defend yourself, reducing damage!\n";
        }

        health -= enemyDamage;
        cout << "The enemy attacks you for " << enemyDamage << " damage!\n";
    }

    if (health <= 0)
    {
        cout << "You were defeated by the enemy!\n";
    }
    else
    {
        cout << "You defeated the enemy!\n";
    }
}

int main()
{
    srand(time(0));
    int choice;

    cout << "Welcome to the Duengeon Adventure!" << '\n';
    cout << "1. Start a New Game!" << '\n';
    cout << "2. Load Game!" << '\n';
    cout << "Enter your choice :" << '\n';
    cin >> choice;

    if (choice == 2)
    {
        loadGame();
    }

    cout << "Your Adventure Begins1" << '\n';

    // Game Loop
    for (int room = 1; room <= 3; room++)
    {
        if (health <= 0)
        {
            cout << "You Died! Game over." << '\n';
            return 0;
        }
        navigateRoom(room);
    }
    cout << "Congratulations! You've escaped the duengeon!<<'\n";
    saveGame();
    return 0;
}