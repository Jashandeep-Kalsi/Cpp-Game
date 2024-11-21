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
void displayInventory();
void saveGame();
void loadGame();
void navigateRoom(int roomNumber){
    cout<<"\nYou enter the Room "<<roomNumber<<'\n';

    if (roomNumber==1)
    {
        cout<<"You see a locked door and a table with a key on it"<<'\n';
        cout<<"1. Pick up the key."<<'\n';
        cout<<"2. Leave the room."<<'\n';

        int choice;
        cin>>choice;
        if (choice==1)
        {
            /* code */
        }
        
    }
    
}
void combat();

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
