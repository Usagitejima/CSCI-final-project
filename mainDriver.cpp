// Donna and Joanne

// include all header files
#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include <vector>
#include <fstream>

int split(string input_string, char separator, string arr[], const int ARR_SIZE);
bool displayLions(string filename, string arr2[5]);

int main()
{

    /*
    1. Ask the user how many players will be playing the game
    2. Update board class with information based on the number of players
    3. Display to terminal all available characters and their stats
    4. Ask player for their name and to select a character and path type
    5. Repeat for remaining players
    6. Game should start and boards should be displayed for each player
    7. Players should be able to see a main menu on their turn that allows them to:
        - Review Pride Point and Leadership Trait stats.
        - Check your character name and age.
        - Display board to view current position.
        - Check who your current advisor is on the game.
        - Move Forward
    8. Code should repeat for each player
    */

    // Varible to store the total number of players
    int numPlayers;

    // Ask the user how many players will be playing and store in numPlayers
    // Run invalid input is out of range and prompt user to reenter a number
    cout << "How many players will be playing the game? (Up to 4 total players)" << endl;
    cin >> numPlayers;
    if (numPlayers > 4 || numPlayers < 1)
    {
        do
        {
            cout << "Invalid number of players. Please choose a number between 1 and 4." << endl;
            cin >> numPlayers;
        } while (numPlayers > 4 || numPlayers < 1);
    }

    // Create a var of board class and store numPlayers
    Board mainBoard(numPlayers);

    // Create a vector for a list of players
    // Prompt user to enter in names of the players and store them into the vector
    vector<string> playersList;
    string currentName;
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "Player " << i + 1 << ", please enter your name: " << endl;
        cin >> currentName;
        playersList.push_back(currentName);
    }

    // Run displayLions functions that shows a list of the characters and their stats
    string lions[5];
    displayLions("characters.txt", lions);

    vector<string> chosenLions;
    string currentLion;

    for (int i = 0; i < numPlayers; i++)
    {
        bool validCharacter = false;
        cout << playersList[i] << ", please select a character by entering its name." << endl;
        cin >> currentLion;
        for (int k = 0; k < 5; k++){
            if (currentLion == lions[k]){
                validCharacter = true;
            }
        }

        if (validCharacter == false)
        {
            do
            {
                cout << "Invalid character. Please enter the name of the character correctly." << endl;
                cin >> currentLion;
                for (int k = 0; k < 5; k++)
                {
                    if (currentLion == lions[k])
                    {
                        validCharacter = true;
                    }
                }
            } while (validCharacter == false);
        }

    }

    // Player _player1("Joanne", 3000, 500, 200);
    // _player1.printStats();
    // _player1.addStamina(300);
    // _player1.printStats();

    // // Code to create another player and print stats
    // // Checks whether printing stats and setting stats work
    // Player _player2("Usagi", 1000, 4000, 700); // 4000 exceeds the limit so it should set stamina to 100
    // _player2.printStats();
    // _player2.setStrength(9000);
    // _player2.printStats();

    // // Code to create a new board
    // // Checks whether initializing and displaying the board works
    // Board board1(2);
    // board1.initializeBoard();
    // board1.displayBoard();

    // _player1.Pink();
    // _player1.printStats();
}

int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    string word;
    int j = 0, k = 0;

    if (input_string.length() == 0)
    {
        return 0;
    }

    for (unsigned int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == separator)
        {
            arr[j] = word;
            word = "";
            j++;
            continue;
        }
        else if (j == ARR_SIZE)
        {
            k++;
            break;
        }
        else
        {
            word += input_string[i];
        }
    }

    arr[j] = word;

    if (j == 0)
    {
        return 1;
    }
    else if (k == 0)
    {
        return ARR_SIZE;
    }
    return -1;
}

bool displayLions(string filename, string arr2[5])
{
    string fullLine;
    int k = 0;

    ifstream fileIn(filename);
    if (fileIn.fail())
    {
        return false;
    }

    getline(fileIn, fullLine);

    while (getline(fileIn, fullLine))
    {

        string arr1[6] = {};
        split(fullLine, '|', arr1, 6);

        cout << "+++++++++++++++++" << endl;
        cout << "Lion name: " << arr1[0] << endl;
        cout << "Age: " << arr1[1] << endl;
        cout << "Strength: " << arr1[2] << endl;
        cout << "Stamina: " << arr1[3] << endl;
        cout << "Wisdom: " << arr1[4] << endl;

        arr2[k] = arr1[0];
        k++;

    }

    return true;
}
