// Donna and Joanne

// include all header files
#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include <vector>
#include <fstream>
#include <iostream>

// Split function to split a line containing a delimiter into multiple parts. Written by Joanne
int split(string input_string, char separator, string arr[], const int ARR_SIZE);
// Display Lions function to display available lion characters and their stats. Written by Joanne
bool displayLions(string filename, string arr2[5]);
// Modify Display Lions function takes list of characters and modifies characters file when a player chooses a character
// Therefore, no duplicates will be chosen. Written by Joanne
void modifyDisplayLions(string filename, string str);
// Output a main menu that will display choices for the user
void outputMenu();
bool displayAdvisors(string filename, string arr2[5]);

int main()
{

    // Write to file the characters that are able to be chosen at the start of game
    ofstream outFile("characters.txt");
    outFile << "playerName|age|strength|stamina|wisdom|pridePoints" << endl
            << "Apollo|5|500|500|1000|20000" << endl
            << "Mane|8|900|600|600|20000" << endl
            << "Elsa|12|900|700|500|20000" << endl
            << "Zuri|7|600|500|900|20000" << endl
            << "Roary|18|1000|500|500|20000" << endl;
    outFile.close();

    Player player1, player2, player3, player4;

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

    // Create a vector for a list of players
    // Prompt user to enter in names of the players and store them into the vector
    vector<string> playersList;
    string currentName;
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "Player " << i + 1 << ", please enter your name: " << endl;
        cin >> currentName;
        playersList.push_back(currentName);
        // Depending on what value of i, assign to corresponding player
        if (i == 0)
        {
            player1.setName(currentName);
        }
        else if (i == 1)
        {
            player2.setName(currentName);
        }
        else if (i == 2)
        {
            player3.setName(currentName);
        }
        else if (i == 3)
        {
            player4.setName(currentName);
        }
    }

    // Run displayLions functions that shows a list of the characters and their stats. Written by Joanne
    string lions[5];
    vector<string> chosenLions;
    string currentLion;

    for (int i = 0; i < numPlayers; i++)
    {
        cout << endl;

        // Start with full list of characters
        if (i == 0)
        {
            displayLions("characters.txt", lions);
        }
        // If any player after first, modify the file so previous player's character does not show up
        else
        {
            modifyDisplayLions("characters.txt", currentLion);
            displayLions("characters.txt", lions);
        }

        cout << endl;

        // Address the player and ask them to select a character
        bool validCharacter = false;
        cout << playersList[i] << ", please select a character by entering its name." << endl;
        cin >> currentLion;

        // Check to make sure that the character entered is in the list of characters
        // If not, prompt the user to enter a character until it is valid
        for (int k = 0; k < 5; k++)
        {
            if (currentLion == lions[k])
            {
                validCharacter = true;
            }
        }

        // If the character the user entered is invalid prompt user to enter the name until one matches
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
                        chosenLions[i] = currentLion;
                    }
                }
            } while (validCharacter == false);
        }

        // Assign stats of the chosen character to corresponding player using setStats function
        if (i == 0)
        {
            player1.setStats("characters.txt", currentLion);
        }
        else if (i == 1)
        {
            player2.setStats("characters.txt", currentLion);
        }
        else if (i == 2)
        {
            player3.setStats("characters.txt", currentLion);
        }
        else if (i == 3)
        {
            player4.setStats("characters.txt", currentLion);
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

    srand(time(0));

    // Create a var of board class and store numPlayers
    Board mainBoard(numPlayers);
    // Initialize and display randomized boards. Written by Donna
    mainBoard.initializePrideBoard();
    mainBoard.displayPrideBoard();
    mainBoard.initializeTrainBoard();
    mainBoard.displayTrainBoard();
    vector<int> pathType;
    int currentType;

    // Output options and prompt user to choose a path type
    // Then, store the decision in a vector. Written by Donna
    cout << "Here are your two possible paths towards Pride Rock! The first path is straight towards Pride Lands and the second path is some Cub Training." << endl;

    for (int i = 0; i < numPlayers; i++)
    {
        cout << playersList[i] << ", please choose your path. (Enter 1 or 2)" << endl;
        cin >> currentType;
        pathType.push_back(currentType);
        if (!(pathType[i] >= 1 && pathType[i] <= 2))
        {
            do
            {
                pathType.pop_back();
                cout << "Invalid input. Please enter 1 or 2." << endl;
                cin >> currentType;
                pathType.push_back(currentType);
            } while (!(pathType[i] >= 1 && pathType[i] <= 2));
        }
    }

    // Code to choose an advisor if you choose cub training
    string advisors[5];
    string currentAdvisor;
    bool validAdvisor = false;

    for (int i = 0; i < numPlayers; i++)
    {
        if (i == 0)
        {
            if (pathType[0] == 2)
            {
                cout << playersList[0] << ", you chose to start with cub training." << endl
                     << "Therefore, you may choose an advisor to help guide you through your journey." << endl;
                displayAdvisors("advisors.txt", advisors);
                cout << "Please enter the name of the advisor you wish to choose." << endl;
                cin >> currentAdvisor;

                for (int k = 0; k < 5; k++)
                {
                    if (currentAdvisor == advisors[k])
                    {
                        validAdvisor = true;
                    }
                }

                // If the character the user entered is invalid prompt user to enter the name until one matches
                if (validAdvisor == false)
                {
                    do
                    {
                        cout << "Invalid advisor. Please enter the name of the advisor correctly." << endl;
                        cin >> currentAdvisor;
                        for (int k = 0; k < 5; k++)
                        {
                            if (currentAdvisor == advisors[k])
                            {
                                validAdvisor = true;
                            }
                        }
                    } while (validAdvisor == false);
                }
            }
        }
        else if (i == 1)
        {
            player2.setName(currentName);
        }
        else if (i == 2)
        {
            player3.setName(currentName);
        }
        else if (i == 3)
        {
            player4.setName(currentName);
        }
    }

    // idea of how to run game?
    // bool endGame = false;

    //     while (endGame == false){

    //     }

    //     cout << mainBoard.movePlayer(1) << endl;
    //     mainBoard.displayPrideBoard();
    //     cout << mainBoard.getPlayerPosition(1) << endl;

    //     mainBoard.displayPrideTrack(1);
}

// Split function to split a line containing a delimiter into multiple parts. Returns the amount of things split. Written by Joanne
int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    string word;
    int j = 0, k = 0;

    // If there is nothing to split, return 0
    if (input_string.length() == 0)
    {
        return 0;
    }

    // Loop to go through the whole line
    for (unsigned int i = 0; i < input_string.length(); i++)
    {
        // If there is a separator found, put the word into the array
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
        // Keep adding characters into the word until it hits a delim
        else
        {
            word += input_string[i];
        }
    }

    // Add remaining word to array
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

// Display Lions function to display available lion characters and their stats. Written by Joanne
bool displayLions(string filename, string arr2[5])
{
    string fullLine;
    int k = 0;

    // Open file and make sure it opens
    ifstream fileIn(filename);
    if (fileIn.fail())
    {
        return false;
    }

    // Skip first line
    getline(fileIn, fullLine);

    // Split each line and print the stats of each lion character
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

    fileIn.close();

    return true;
}

// Modify Display Lions function takes list of characters and modifies characters file when a player chooses a character
// Therefore, no duplicates will be chosen. Written by Joanne
void modifyDisplayLions(string filename, string str)
{
    string fullLine;
    vector<string> currentNames;
    vector<string> fullLines;
    int p = 0;

    // Open file and make sure it opens
    ifstream fileIn(filename);
    if (fileIn.fail())
    {
        return;
    }

    // Split each line in the characters file and add each of the characters' name to a vector

    while (getline(fileIn, fullLine))
    {
        fullLines.push_back(fullLine);
        string array1[6];
        split(fullLine, '|', array1, 6);
        currentNames.push_back(array1[0]);
        p++;
    }

    fileIn.close();

    // Open file as output
    ofstream fileOut(filename);

    // If the name chosen by the user is in the file, break the loop (skip that line)
    // If not, then add the line of the character into a new file (temp)
    int vecsize = fullLines.size();
    for (int i = 0; i < vecsize; i++)
    {
        if (str == currentNames[i])
        {
            continue;
        }
        else
        {

            fileOut << fullLines[i] << endl;
        }
    }
}

// Output a main menu that will display choices for the user
void outputMenu()
{
    cout << "+++ Main Menu +++" << endl
         << "1. Review pride points and leadership trait stats" << endl
         << "2. Check character name and age" << endl
         << "3. Display board to view current position" << endl
         << "4. Check current advisor" << endl
         << "5. Move forward" << endl
         << "Please enter your choice (1 - 5):" << endl;
}

bool displayAdvisors(string filename, string arr2[5])
{
    string fullLine;
    int k = 0;

    // Open file and make sure it opens
    ifstream fileIn(filename);
    if (fileIn.fail())
    {
        return false;
    }

    // Skip first line
    getline(fileIn, fullLine);

    // Split each line and print the stats of each lion character
    while (getline(fileIn, fullLine))
    {

        string arr1[3] = {};
        split(fullLine, '|', arr1, 3);

        cout << "+++++++++++++++++" << endl;
        cout << "Advisor name: " << arr1[0] << endl;
        cout << "Skill: " << arr1[1] << endl;
        cout << "Description: " << arr1[2] << endl;

        arr2[k] = arr1[0];
        k++;
    }

    fileIn.close();

    return true;
}