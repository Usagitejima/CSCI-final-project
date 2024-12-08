// Donna and Joanne

// include all header files
#include "Board.h"
#include "Player.h"
#include "Tile.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

// Split function to split a line containing a delimiter into multiple parts. Written by Joanne
int split(string input_string, char separator, string arr[], const int ARR_SIZE);
// Display Lions function to display available lion characters and their stats. Written by Joanne
bool displayLions(string filename, string arr2[5]);
// Modify Display Lions function takes list of characters and modifies characters file when a player chooses a character
// Therefore, no duplicates will be chosen. Written by Joanne
void modifyDisplayLions(string filename, string str);
// Output a main menu that will display choices for the user
void outputMenu();
// Displays the list of advisors and their skills/descriptions.
bool displayAdvisors(string filename, string arr2[5]);
// Runs menu choice one, which allows the player to look at their stats and pride points
void menu1(Player currentPlayer, int currentPlayerIndex, vector<string> list);
// Runs menu choice two, which allows player to see their name and age
void menu2(Player currentPlayer, int currentPlayerIndex, vector<string> list);
// Runs menu choice three, which allows the player to see their current position on the path they chose
void menu3(Board _board, int currentPlayerIndex, int prideortrain, int arr[]);
// Runs menu choice four, which allows the player to check their current advisor
void menu4(int currentPlayerIndex, string advisor, string filename, vector<string> list);
// Runs menu choice five, which allows the player to roll the dice and move forward
bool menu5(Board _board, int currentPlayerIndex, int vec, int arr[]);
// Checks whether the string value is a valid integer or not. Written by Donna
bool isValidInt(string value);
// Hyena Tile, lose 100 stamina and strength, player must go back three spaces. Written by Donna
void brownTile(Board _board, int currentPlayerIndex, int vec, int arr[]);
// Oasis Tile, returns 100. Written by Joanne
int blueTile();
// Advisor Tile, allows user to choose a new advisor or stick with their current one. Only applicable for Cub Training Tile. Written by Joanne
int pinkTile(string advisors[], string chosenAdvisors[], int currentPlayerIndex, Player currentPlayer);
// Random Event Tile, chooses a random event that may only be bypassed with a certain amount of leadership points. Advisor choice
// also plays a big part in how events may be bypassed or affected. Written by Joanne
int greenTile(string chosenAdvisors[], int currentPlayerIndex, string filename, Player currentPlayer);
bool purpleTile(string filename);
int redTile(Board _board, int currentPlayerIndex, int vec, int arr[]);
// Function that converts leadership points to pride points
// For every 100 leadership points, player gains 1,000 pride points
int convertLeadershipPoints(Player currentPlayer);

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
    string SnumPlayers;

    cout << R"(
                        \|\||
                      -' ||||/
                     /7   |||||/
         |\_        /    |||||||/`-.____________
       -' | \       \-' |||||||||               `-._
      /7     \       -|||||||||||               `` -`.
     /        `-_      ||||||               \   |   `\\
     \-'_        `-.____|||||\  \______...---\_  \    \\
      -- \                 |  \  \           | \  |    ``-.__--.
         /                 |  |\  \         / / | |       ``---'
 _______/    /_       ____/  /_/  /|_______/ /-_| |
(,__________/  `-.___(,_(,__/(,__/_-----(,__/-(,__/

    )";

    cout << "LION KING: THE GAME" << endl;
    cout << "Created by Donna and Joanne" << endl;
    cout << endl;

    // Ask the user how many players will be playing and store in numPlayers
    // Run invalid input is out of range and prompt user to reenter a number
    cout << "Welcome!" << endl;
    while (true)
    {
        cout << "How many players will be playing the game? (Up to 4 total players)" << endl;
        if (cin >> SnumPlayers && isValidInt(SnumPlayers) == true && stoi(SnumPlayers) <= 4 && stoi(SnumPlayers) > 1)
        {
            numPlayers = stoi(SnumPlayers);
            break;
        }
        else
        {
            cout << "Invalid number of players. Please choose a number between 1 and 4." << endl;
            cin.clear();  // reset the failbit
            cin.ignore(); // discard the invalid input
        }
    }

    // Create a vector for a list of players
    // Prompt user to enter in names of the players and store them into the vector
    vector<string> playersList;
    string currentName;
    for (int i = 0; i < numPlayers; i++)
    {
        cout << endl;
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

        // Start with full list of characters
        if (i == 0)
        {
            cout << endl;
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

        while (validCharacter == false)
        {
            cout << playersList[i] << ", please select a character by entering its name." << endl;
            cin >> currentLion;
            for (int k = 0; k < 5; k++)
            {
                if (currentLion == lions[k])
                {
                    validCharacter = true;
                    cout << endl;
                    break;
                }
            }
            if (validCharacter == false)
            {
                cout << "Invalid character. Please enter the name of the character correctly." << endl;
                cin.clear();  // reset the failbit
                cin.ignore(); // discard the invalid input
                cout << endl;
            }
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
    string ScurrentType;

    // Output options and prompt user to choose a path type
    // Then, store the decision in a vector. Prompt user to reenter input if invalid (not 1 or 2). Written by Donna
    cout << "Here are your two possible paths towards Pride Rock! The first path is straight towards Pride Lands and the second path is some Cub Training." << endl;
    cout << "Going to the Pride Lands adds 200 Stamina Points, 200 Strength Points, and 200 Wisdom Points, as well as a boost of 5,000 Pride Points" << endl;
    cout << "Recieving Cub Training adds 500 Stamina Points, 500 Strength Points, and 1,000 Wisdom Points, but you lose 5,000 Pride Points" << endl;

    for (int i = 0; i < numPlayers; i++)
    {
        while (true)
        {
            cout << playersList[i] << ", please choose your path. (Enter 1 or 2)" << endl;
            if (cin >> ScurrentType && isValidInt(ScurrentType) && (stoi(ScurrentType) == 1 || stoi(ScurrentType) == 2))
            {
                currentType = stoi(ScurrentType);
                pathType.push_back(currentType);
                if (i == 0)
                        {
                            if (ScurrentType == "1"){
                                // player1.printStats();
                                player1.toPrideLands();
                            }
                            else if (ScurrentType == "2"){
                                player1.trainCub();
                            }
                        }
                        else if (i == 1)
                        {
                            if (ScurrentType == "1"){
                                player2.toPrideLands();
                            }
                            else if (ScurrentType == "2"){
                                // player2.printStats();
                                player2.trainCub();
                                // player2.printStats();
                            }
                        }
                        else if (i == 2)
                        {
                            if (ScurrentType == "1"){
                                player3.toPrideLands();
                            }
                            else if (ScurrentType == "2"){
                                player3.trainCub();
                            }
                        }
                        else if (i == 3){
                            if (ScurrentType == "1"){
                                player4.toPrideLands();
                            }
                            else if (ScurrentType == "2"){
                                player4.trainCub();
                            }
                        }
                break;
            }
            else
            {
                cout << "Invalid input. Please enter 1 or 2." << endl;
                cin.clear();  // reset the failbit
                cin.ignore(); // discard the invalid input
            }
        }
    }

    // Code to choose an advisor if you choose cub training
    string advisors[5];
    string chosenAdvisors[4];
    string currentAdvisor;
    bool validAdvisor = false;
    vector<bool> haveAdvisor(4);

    // Display the various advisors from txt file
    for (int i = 0; i < numPlayers; i++)
    {
        if (i == 0)
        {
            if (pathType[0] == 2)
            {
                haveAdvisor[0] = true; 
                displayAdvisors("advisors.txt", advisors);
                cout << playersList[0] << ", you chose to start with cub training." << endl
                     << "Therefore, you may choose an advisor to help guide you through your journey." << endl;
                cout << "Please enter the name of the advisor you wish to choose." << endl;
                cin >> currentAdvisor;

                for (int k = 0; k < 5; k++)
                {
                    if (currentAdvisor == advisors[k])
                    {
                        validAdvisor = true;
                        chosenAdvisors[0] = currentAdvisor;
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
                                chosenAdvisors[0] = currentAdvisor;
                            }
                        }
                    } while (validAdvisor == false);
                }
            }
        }
        else if (i == 1)
        {
            if (pathType[1] == 2)
            {
                haveAdvisor[1] = true; 
                displayAdvisors("advisors.txt", advisors);
                cout << playersList[1] << ", you chose to start with cub training." << endl
                     << "Therefore, you may choose an advisor to help guide you through your journey." << endl;
                cout << "Please enter the name of the advisor you wish to choose." << endl;
                cin >> currentAdvisor;

                for (int k = 0; k < 5; k++)
                {
                    if (currentAdvisor == advisors[k])
                    {
                        validAdvisor = true;
                        chosenAdvisors[1] = currentAdvisor;
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
                                chosenAdvisors[1] = currentAdvisor;
                            }
                        }
                    } while (validAdvisor == false);
                }
            }
        }
        else if (i == 2)
        {
            if (pathType[2] == 2)
            {
                haveAdvisor[2] = true; 
                displayAdvisors("advisors.txt", advisors);
                cout << playersList[2] << ", you chose to start with cub training." << endl
                     << "Therefore, you may choose an advisor to help guide you through your journey." << endl;
                cout << "Please enter the name of the advisor you wish to choose." << endl;
                cin >> currentAdvisor;

                for (int k = 0; k < 5; k++)
                {
                    if (currentAdvisor == advisors[k])
                    {
                        validAdvisor = true;
                        chosenAdvisors[2] = currentAdvisor;
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
                                chosenAdvisors[2] = currentAdvisor;
                            }
                        }
                    } while (validAdvisor == false);
                }
            }
        }
        else if (i == 3)
        {
            if (pathType[3] == 2)
            {
                haveAdvisor[3] = true; 
                displayAdvisors("advisors.txt", advisors);
                cout << playersList[3] << ", you chose to start with cub training." << endl
                     << "Therefore, you may choose an advisor to help guide you through your journey." << endl;
                cout << "Please enter the name of the advisor you wish to choose." << endl;
                cin >> currentAdvisor;

                for (int k = 0; k < 5; k++)
                {
                    if (currentAdvisor == advisors[k])
                    {
                        validAdvisor = true;
                        chosenAdvisors[3] = currentAdvisor;
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
                                chosenAdvisors[3] = currentAdvisor;
                            }
                        }
                    } while (validAdvisor == false);
                }
            }
        }
        cout << endl;
    }

    // idea of how to run game?
    bool endGame = false;
    bool endTurn = false;
    bool prideRocks[4] = {0, 0, 0, 0};
    int counter = 0;
    int choice;
    string Schoice;
    int currentPositions[4] = {0, 0, 0, 0};

    while (endGame == false)
    {
        cout << "Starting game..." << endl;

        for (int turnCount = 0; turnCount < numPlayers; turnCount++)
        {
            if (turnCount == 0)
            {
                // Display menu and allow user to make a choice. Only move turns when play chooses to move position
                do
                {
                    endTurn = false;
                    if (prideRocks[0] == true)
                    {
                        endTurn = true;
                    }
                    else
                    {
                        outputMenu();
                        while (true)
                        {
                            cout << playersList[0] << ", please enter your choice (1 - 5):" << endl;
                            cin >> Schoice;
                            if (isValidInt(Schoice) == false || stoi(Schoice) > 5 || stoi(Schoice) < 1)
                            {
                                cout << "Invalid input. " << endl;
                                cin.clear();  // reset the failbit
                                cin.ignore(); // discard the invalid input
                            }
                            else
                            {
                                choice = stoi(Schoice);
                                break;
                            }
                        }
                        if (choice == 1)
                        {
                            menu1(player1, 0, playersList);
                        }
                        else if (choice == 2)
                        {
                            menu2(player1, 0, playersList);
                        }
                        else if (choice == 3)
                        {
                            menu3(mainBoard, 0, pathType[0], currentPositions);
                        }
                        else if (choice == 4)
                        {
                            menu4(0, chosenAdvisors[0], "advisors.txt", playersList);
                        }
                        else if (choice == 5)
                        {
                            prideRocks[0] = menu5(mainBoard, 0, pathType[0], currentPositions);
                            if (prideRocks[0] == true){
                                break;
                            }

                            // Case Purple
                            if (mainBoard.determineColor(0, pathType[0], currentPositions[0]) == 'U')
                            {
                                if(purpleTile("riddles.txt") == false){
                                    cout << "Wrong answer! You have lost (-300) Wisdom Points out of shame!" << endl;
                                    cout << "Your Wisdom Points: " << endl << player1.getWisdom() << " -> ";
                                    player1.addWisdom(-300);
                                    cout << player1.getWisdom() << endl;
                                }
                                else{
                                    cout << "Correct answer! You have gained (+500) Wisdom Points!" << endl;
                                    cout << "Your Wisdom Points: " << endl << player1.getWisdom() << " -> ";
                                    player1.addWisdom(500);
                                    cout << player1.getWisdom() << endl;
                                }
                            }

                            // Case Brown
                            while (mainBoard.determineColor(0, pathType[0], currentPositions[0]) == 'N')
                            {
                                cout << "Your Strength: " << endl << player1.getStrength() << " -> ";
                                player1.addStrength(-100);
                                cout << player1.getStrength() << endl;
                                cout << "Your Stamina: " << endl << player1.getStamina() << " -> ";
                                player1.addStamina(-100);
                                cout << player1.getStamina() << endl;
                                brownTile(mainBoard, 0, pathType[0], currentPositions);
                            }

                            // Case Blue
                            if (mainBoard.determineColor(0, pathType[0], currentPositions[0]) == 'B')
                            {
                                cout << "You have reached an oasis. Take a break and recover your strength, stamina, widsom (+100)" << endl;
                                cout << "Your Strength: " << endl << player1.getStrength() << " -> ";
                                player1.addStrength(blueTile());
                                cout << player1.getStrength() << endl;
                                cout << "Your Stamina: " << endl << player1.getStamina() << " -> ";
                                player1.addStamina(blueTile());
                                cout << player1.getStamina() << endl;
                                cout << "Your Wisdom: " << endl << player1.getWisdom() << " -> ";
                                player1.addWisdom(blueTile());
                                cout << player1.getWisdom() << endl;
                            }

                            // Case Pink
                            if (mainBoard.determineColor(0, pathType[0], currentPositions[0]) == 'P')
                            {
                                player1.addPridePoints(pinkTile(advisors, chosenAdvisors, 0, player1));
                                cout << player1.getPride() << endl;
                                cout << "Your new advisor: " << chosenAdvisors[0] << endl;
                            }

                            // Case Green
                            if (mainBoard.determineColor(0, pathType[0], currentPositions[0]) == 'G')
                            {
                                cout << "Your Strength: " << player1.getStrength() << endl;
                                cout << "Your Stamina: " << player1.getStamina() << endl;
                                cout << "Your Wisdom: " << player1.getWisdom() << endl;
                                cout << "Your Pride Points: " << player1.getPride() << endl;
                                player1.addPridePoints(greenTile(chosenAdvisors, 0, "randomEvents.txt", player1));
                                cout << "Your Pride Points: " << player1.getPride() << endl;
                            }

                            // Case Red
                            while(mainBoard.determineColor(0, pathType[0], currentPositions[0]) == 'R'){
                                int choice = redTile(mainBoard, 0, pathType[0], currentPositions);
                                if(choice == 0){
                                    break;
                                }
                                else if(choice == 1){
                                    displayAdvisors("advisors.txt", advisors);
                                    cout << playersList[0] << ", please choose your advisor to guide you through your journey." << endl;
                                    cin >> currentAdvisor;

                                    for (int k = 0; k < 5; k++)
                                    {
                                        if (currentAdvisor == advisors[k])
                                        {
                                            validAdvisor = true;
                                            chosenAdvisors[0] = currentAdvisor;
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
                                                    chosenAdvisors[0] = currentAdvisor;
                                                }
                                            }
                                        } while (validAdvisor == false);
                                    }
                                }
                                else{
                                    cout << "Your Pride Points: " << endl << player1.getPride() << " -> ";
                                    player1.addPridePoints(500);
                                    cout << player1.getPride() << endl;

                                    cout << "Your Stamina: " << endl << player1.getStamina() << " -> ";
                                    player1.addStamina(500);
                                    cout << player1.getStamina() << endl;

                                    cout << "Your Strength: " << endl << player1.getStrength() << " -> ";
                                    player1.addStrength(500);
                                    cout << player1.getStrength() << endl;
                                    
                                    cout << "Your Wisdom Points: " << endl << player1.getWisdom() << " -> ";
                                    player1.addWisdom(500);
                                    cout << player1.getWisdom() << endl;
                                }
                            }

                            endTurn = true;
                        }
                    }
                } while (endTurn == false);
            }
            else if (turnCount == 1)
            {
                do
                {
                    endTurn = false;
                    if (prideRocks[1] == true)
                    {
                        endTurn = true;
                    }
                    else
                    {
                        outputMenu();
                        while (true)
                        {
                            cout << playersList[1] << ", please enter your choice (1 - 5):" << endl;
                            cin >> Schoice;
                            if (isValidInt(Schoice) == false || stoi(Schoice) > 5 || stoi(Schoice) < 1)
                            {
                                cout << "Invalid input. " << endl;
                                cin.clear();  // reset the failbit
                                cin.ignore(); // discard the invalid input
                            }
                            else
                            {
                                choice = stoi(Schoice);
                                break;
                            }
                        }
                        if (choice == 1)
                        {
                            menu1(player2, 1, playersList);
                        }
                        else if (choice == 2)
                        {
                            menu2(player2, 1, playersList);
                        }
                        else if (choice == 3)
                        {
                            menu3(mainBoard, 1, pathType[1], currentPositions);
                        }
                        else if (choice == 4)
                        {
                            menu4(1, chosenAdvisors[1], "advisors.txt", playersList);
                        }
                        else if (choice == 5)
                        {
                            prideRocks[1] = menu5(mainBoard, 1, pathType[1], currentPositions);
                            if (prideRocks[1] == true){
                                break;
                            }

                            // Case Purple
                            if (mainBoard.determineColor(1, pathType[1], currentPositions[1]) == 'U')
                            {
                                if(purpleTile("riddles.txt") == false){
                                    cout << "Wrong answer! You have lost (-300) Wisdom Points out of shame!" << endl;
                                    cout << "Your Wisdom Points: " << endl << player2.getWisdom() << " -> ";
                                    player2.addWisdom(-300);
                                    cout << player2.getWisdom() << endl;
                                }
                                else{
                                    cout << "Correct answer! You have gained (+500) Wisdom Points!" << endl;
                                    cout << "Your Wisdom Points: " << endl << player2.getWisdom() << " -> ";
                                    player2.addWisdom(500);
                                    cout << player2.getWisdom() << endl;
                                }
                            }

                            // Case Brown
                            while (mainBoard.determineColor(1, pathType[1], currentPositions[1]) == 'N')
                            {
                                cout << "Your Strength: " << endl << player2.getStrength() << " -> ";
                                player2.addStrength(-100);
                                cout << player2.getStrength() << endl;
                                cout << "Your Stamina: " << endl << player2.getStamina() << " -> ";
                                player2.addStamina(-100);
                                cout << player2.getStamina() << endl;
                                brownTile(mainBoard, 1, pathType[1], currentPositions);
                            }

                            // Case Blue
                            if (mainBoard.determineColor(1, pathType[1], currentPositions[1]) == 'B')
                            {
                                cout << "You have reached an oasis. Take a break and recover your strength, stamina, widsom (+100)" << endl;
                                cout << "Your Strength: " << endl << player2.getStrength() << " -> ";
                                player2.addStrength(blueTile());
                                cout << player2.getStrength() << endl;
                                cout << "Your Stamina: " << endl << player2.getStamina() << " -> ";
                                player2.addStamina(blueTile());
                                cout << player2.getStamina() << endl;
                                cout << "Your Wisdom: " << endl << player2.getWisdom() << " -> ";
                                player2.addWisdom(blueTile());
                                cout << player2.getWisdom() << endl;
                            }

                            // Case Pink
                            if (mainBoard.determineColor(1, pathType[1], currentPositions[1]) == 'P')
                            {
                                player2.addPridePoints(pinkTile(advisors, chosenAdvisors, 1, player2));
                                cout << player2.getPride() << endl;
                                cout << "Your new advisor: " << chosenAdvisors[1] << endl;
                            }

                            // Case Green
                            if (mainBoard.determineColor(1, pathType[1], currentPositions[1]) == 'G')
                            {
                                cout << "Your Strength: " << player2.getStrength() << endl;
                                cout << "Your Stamina: " << player2.getStamina() << endl;
                                cout << "Your Wisdom: " << player2.getWisdom() << endl;
                                cout << "Your Pride Points: " << player2.getPride() << endl;
                                player2.addPridePoints(greenTile(chosenAdvisors, 1, "randomEvents.txt", player2));
                                cout << "Your Pride Points: " << player2.getPride() << endl;
                            }

                            endTurn = true;
                        }
                    }
                } while (endTurn == false);
            }
            else if (turnCount == 2)
            {
                do
                {
                    endTurn = false;
                    if (prideRocks[2] == true)
                    {
                        endTurn = true;
                    }
                    outputMenu();
                    while (true)
                    {
                        cout << playersList[2] << ", please enter your choice (1 - 5):" << endl;
                        cin >> Schoice;
                        if (isValidInt(Schoice) == false || stoi(Schoice) > 5 || stoi(Schoice) < 1)
                        {
                            cout << "Invalid input. " << endl;
                            cin.clear();  // reset the failbit
                            cin.ignore(); // discard the invalid input
                        }
                        else
                        {
                            choice = stoi(Schoice);
                            break;
                        }
                    }
                    if (choice == 1)
                    {
                        menu1(player3, 2, playersList);
                    }
                    else if (choice == 2)
                    {
                        menu2(player3, 2, playersList);
                    }
                    else if (choice == 3)
                    {
                        menu3(mainBoard, 2, pathType[2], currentPositions);
                    }
                    else if (choice == 4)
                    {
                        menu4(2, chosenAdvisors[2], "advisors.txt", playersList);
                    }
                    else if (choice == 5)
                        {
                            prideRocks[2] = menu5(mainBoard, 2, pathType[2], currentPositions);
                            if (prideRocks[2] == true){
                                break;
                            }

                            // Case Purple
                            if (mainBoard.determineColor(2, pathType[2], currentPositions[2]) == 'U')
                            {
                                if(purpleTile("riddles.txt") == false){
                                    cout << "Wrong answer! You have lost (-300) Wisdom Points out of shame!" << endl;
                                    cout << "Your Wisdom Points: " << endl << player3.getWisdom() << " -> ";
                                    player3.addWisdom(-300);
                                    cout << player3.getWisdom() << endl;
                                }
                                else{
                                    cout << "Correct answer! You have gained (+500) Wisdom Points!" << endl;
                                    cout << "Your Wisdom Points: " << endl << player3.getWisdom() << " -> ";
                                    player3.addWisdom(500);
                                    cout << player3.getWisdom() << endl;
                                }
                            }

                            // Case Brown
                            while (mainBoard.determineColor(2, pathType[2], currentPositions[2]) == 'N')
                            {
                                cout << "Your Strength: " << endl << player3.getStrength() << " -> ";
                                player3.addStrength(-100);
                                cout << player3.getStrength() << endl;
                                cout << "Your Stamina: " << endl << player3.getStamina() << " -> ";
                                player3.addStamina(-100);
                                cout << player3.getStamina() << endl;
                                brownTile(mainBoard, 2, pathType[2], currentPositions);
                            }

                            // Case Blue
                            if (mainBoard.determineColor(2, pathType[2], currentPositions[2]) == 'B')
                            {
                                cout << "You have reached an oasis. Take a break and recover your strength, stamina, widsom (+100)" << endl;
                                cout << "Your Strength: " << endl << player3.getStrength() << " -> ";
                                player3.addStrength(blueTile());
                                cout << player3.getStrength() << endl;
                                cout << "Your Stamina: " << endl << player3.getStamina() << " -> ";
                                player3.addStamina(blueTile());
                                cout << player3.getStamina() << endl;
                                cout << "Your Wisdom: " << endl << player3.getWisdom() << " -> ";
                                player3.addWisdom(blueTile());
                                cout << player3.getWisdom() << endl;
                            }

                            // Case Pink
                            if (mainBoard.determineColor(2, pathType[2], currentPositions[2]) == 'P')
                            {
                                player3.addPridePoints(pinkTile(advisors, chosenAdvisors, 2, player3));
                                cout << player3.getPride() << endl;
                                cout << "Your new advisor: " << chosenAdvisors[2] << endl;
                            }

                            // Case Green
                            if (mainBoard.determineColor(2, pathType[2], currentPositions[2]) == 'G')
                            {
                                cout << "Your Strength: " << player3.getStrength() << endl;
                                cout << "Your Stamina: " << player3.getStamina() << endl;
                                cout << "Your Wisdom: " << player3.getWisdom() << endl;
                                cout << "Your Pride Points: " << player3.getPride() << endl;
                                player3.addPridePoints(greenTile(chosenAdvisors, 2, "randomEvents.txt", player3));
                                cout << "Your Pride Points: " << player3.getPride() << endl;
                            }

                            endTurn = true;
                        }
                    } 
                    while (endTurn == false);
            } 
            else if (turnCount == 3)
            {
                do
                {
                    endTurn = false;
                    if (prideRocks[3] == true)
                    {
                        endTurn = true;
                    }
                    outputMenu();
                    while (true)
                    {
                        cout << playersList[3] << ", please enter your choice (1 - 5):" << endl;
                        cin >> Schoice;
                        if (isValidInt(Schoice) == false || stoi(Schoice) > 5 || stoi(Schoice) < 1)
                        {
                            cout << "Invalid input. " << endl;
                            cin.clear();  // reset the failbit
                            cin.ignore(); // discard the invalid input
                        }
                        else
                        {
                            choice = stoi(Schoice);
                            break;
                        }
                    }
                    if (choice == 1)
                    {
                        menu1(player4, 3, playersList);
                    }
                    else if (choice == 2)
                    {
                        menu2(player4, 3, playersList);
                    }
                    else if (choice == 3)
                    {
                        menu3(mainBoard, 3, pathType[3], currentPositions);
                    }
                    else if (choice == 4)
                    {
                        menu4(3, chosenAdvisors[3], "advisors.txt", playersList);
                    }
                    else if (choice == 5)
                    {
                        prideRocks[3] = menu5(mainBoard, 3, pathType[3], currentPositions);
                            if (prideRocks[3] == true){
                                break;
                            }

                            // Case Purple
                            if (mainBoard.determineColor(3, pathType[3], currentPositions[3]) == 'U')
                            {
                                if(purpleTile("riddles.txt") == false){
                                    cout << "Wrong answer! You have lost (-300) Wisdom Points out of shame!" << endl;
                                    cout << "Your Wisdom Points: " << endl << player4.getWisdom() << " -> ";
                                    player4.addWisdom(-300);
                                    cout << player4.getWisdom() << endl;
                                }
                                else{
                                    cout << "Correct answer! You have gained (+500) Wisdom Points!" << endl;
                                    cout << "Your Wisdom Points: " << endl << player4.getWisdom() << " -> ";
                                    player4.addWisdom(500);
                                    cout << player4.getWisdom() << endl;
                                }
                            }

                            // Case Brown
                            while (mainBoard.determineColor(3, pathType[3], currentPositions[3]) == 'N')
                            {
                                cout << "Your Strength: " << endl << player1.getStrength() << " -> ";
                                player4.addStrength(-100);
                                cout << player4.getStrength() << endl;
                                cout << "Your Stamina: " << endl << player4.getStamina() << " -> ";
                                player4.addStamina(-100);
                                cout << player4.getStamina() << endl;
                                brownTile(mainBoard, 3, pathType[3], currentPositions);
                            }

                            // Case Blue
                            if (mainBoard.determineColor(3, pathType[3], currentPositions[3]) == 'B')
                            {
                                cout << "You have reached an oasis. Take a break and recover your strength, stamina, widsom (+100)" << endl;
                                cout << "Your Strength: " << endl << player4.getStrength() << " -> ";
                                player4.addStrength(blueTile());
                                cout << player4.getStrength() << endl;
                                cout << "Your Stamina: " << endl << player4.getStamina() << " -> ";
                                player4.addStamina(blueTile());
                                cout << player4.getStamina() << endl;
                                cout << "Your Wisdom: " << endl << player4.getWisdom() << " -> ";
                                player4.addWisdom(blueTile());
                                cout << player4.getWisdom() << endl;
                            }

                            // Case Pink
                            if (mainBoard.determineColor(3, pathType[3], currentPositions[3]) == 'P')
                            {
                                player4.addPridePoints(pinkTile(advisors, chosenAdvisors, 3, player4));
                                cout << player4.getPride() << endl;
                                cout << "Your new advisor: " << chosenAdvisors[3] << endl;
                            }

                            // Case Green
                            if (mainBoard.determineColor(3, pathType[3], currentPositions[3]) == 'G')
                            {
                                cout << "Your Strength: " << player4.getStrength() << endl;
                                cout << "Your Stamina: " << player4.getStamina() << endl;
                                cout << "Your Wisdom: " << player4.getWisdom() << endl;
                                cout << "Your Pride Points: " << player4.getPride() << endl;
                                player4.addPridePoints(greenTile(chosenAdvisors, 3, "randomEvents.txt", player4));
                                cout << "Your Pride Points: " << player4.getPride() << endl;
                            }

                            endTurn = true;
                    }
                } while (endTurn == false);
            }

            counter = 0;
            for (int m = 0; m < numPlayers; m++)
            {
                if (prideRocks[m] == true)
                {
                    counter++;
                }
                else
                {
                    break;
                }
            }

            if (counter == numPlayers)
            {
                endGame = true;
            }
            // Keep loop running
            else if (turnCount == numPlayers - 1)
            {
                turnCount = -1;
            }
        }
    }

    cout << "All players have reached Pride Rock! Ending game..." << endl;

    player1.addPridePoints(convertLeadershipPoints(player1));
    player2.addPridePoints(convertLeadershipPoints(player2));
    player3.addPridePoints(convertLeadershipPoints(player2));
    player4.addPridePoints(convertLeadershipPoints(player2));

    // vector<int> finalPride;

    // for (int k = 0; k < numPlayers; k++){
    //     if (k == 0){
    //     finalPride.push_back(player1.getPride());
    //     } else if (k == 1){
    //     finalPride.push_back(player2.getPride());
    //     } else if (k == 2){
    //     finalPride.push_back(player3.getPride());
    //     } else if (k == 3){
    //     finalPride.push_back(player4.getPride());
    //     }
    // }

    // int temp;
    // string _temp;
    // for (int a = 0; a < numPlayers; a++){
    //     for (int b = 0; b < numPlayers; b++){
    //         if (finalPride[a] > finalPride[b]){
    //             temp = finalPride[b];
    //             _temp = playersList[b];
    //             finalPride[b] = finalPride[a];
    //             playersList[b] = playersList[a];
    //             finalPride[a] = temp;
    //             playersList[a] = _temp;
    //         }
    //     }
    // }

    // for (int c = 0; c < numPlayers; c++){
    //     if (c == 0){
    //     cout << "In first is " << playersList[3] << ", with " << finalPride[3] << " pride points!";
    //     } else if (c == 1){
    //     cout << "In first is " << playersList[2] << ", with " << finalPride[2] << " pride points!";
    //     } else if (c == 2){
    //     cout << "In first is " << playersList[1] << ", with " << finalPride[1] << " pride points!";
    //     } else if (c == 3){
    //     cout << "In first is " << playersList[0] << ", with " << finalPride[0] << " pride points!";
    //     }
    // }


}

// Check if a string is a valid integer
bool isValidInt(string value)
{
    for (int i = 0; i < (int)value.length(); i++)
    {
        if (!isdigit(value[i]))
        {
            return false;
        }
    }
    return true;
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

// Split function to split a line containing a delimiter int multiple parts and stores them in a vector, which is what is returned.
vector<string> splitVec(string input_string, char separator, const int size)
{
    vector<string> vecWords;
    string word;
    int j = 0, k = 0;

    // If there is nothing to split, return 0
    if (input_string.length() == 0)
    {
        return vecWords;
    }

    // Loop to go through the whole line
    for (unsigned int i = 0; i < input_string.length(); i++)
    {
        // If there is a separator found, put the word into the array
        if (input_string[i] == separator)
        {
            vecWords.push_back(word);
            word = "";
            j++;
            continue;
        }
        else if (j == size)
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
    vecWords.push_back(word);

    return vecWords;
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
    cout << endl;
    cout << "+++ Main Menu +++" << endl
         << "1. Review pride points and leadership trait stats" << endl
         << "2. Check character name and age" << endl
         << "3. Display board to view current position" << endl
         << "4. Check current advisor" << endl
         << "5. Move forward" << endl;
}

// Displays the list of advisors and their skills/descriptions.
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
        cout << endl;

        arr2[k] = arr1[0];
        k++;
    }

    fileIn.close();

    return true;
}

// Runs menu choice one, which allows the player to look at their stats and pride points
void menu1(Player currentPlayer, int currentPlayerIndex, vector<string> list)
{
    cout << endl;
    cout << list[currentPlayerIndex] << ", here are your pride points and leadership trait stats: " << endl;
    cout << "Strength: " << currentPlayer.getStrength() << endl;
    cout << "Stamina: " << currentPlayer.getStamina() << endl;
    cout << "Wisdom: " << currentPlayer.getWisdom() << endl;
    cout << "Pride Points: " << currentPlayer.getPride() << endl;
}

// Runs menu choice two, which allows player to see their name and age
void menu2(Player currentPlayer, int currentPlayerIndex, vector<string> list)
{
    cout << endl;
    cout << list[currentPlayerIndex] << ", here is your name and age: " << endl;
    cout << "Name: " << currentPlayer.getName() << endl;
    cout << "Age: " << currentPlayer.getAge() << endl;
}

// Runs menu choice three, which allows the player to see their current position on the path they chose
void menu3(Board _board, int currentPlayerIndex, int prideortrain, int arr[])
{
    cout << endl;
    // Depending on which path type user chose
    if (prideortrain == 1)
    {
        // Move the position to the current one
        _board.movePlayer(currentPlayerIndex, arr[currentPlayerIndex]);
        // Display the specific user's path
        _board.displayPrideTrack(currentPlayerIndex);
    }
    else if (prideortrain == 2)
    {
        // Move the position to the current one
        _board.movePlayer(currentPlayerIndex, arr[currentPlayerIndex]);
        // Display the specific user's path
        _board.displayTrainTrack(currentPlayerIndex);
    }
}

// Runs menu choice four, which allows the player to check their current advisor
void menu4(int currentPlayerIndex, string advisor, string filename, vector<string> list)
{
    cout << endl;
    string fullLine;
    vector<string> advisors;
    int k = 0;

    // Open file and make sure it opens
    ifstream fileIn(filename);

    getline(fileIn, fullLine);

    // Split each line and print the stats of each lion character
    while (getline(fileIn, fullLine))
    {

        advisors = splitVec(fullLine, '|', 3);

        if (advisor == "")
        {
            cout << "You currently do not have an advisor." << endl;
            break;
        }
        else if (advisor == advisors[0])
        {
            cout << list[currentPlayerIndex] << "'s Advisor: " << advisors[0] << endl;
            cout << "Skill: " << advisors[1] << endl;
            cout << "Description: " << advisors[2] << endl;
        }

        k++;
    }

    fileIn.close();
}

// Runs menu choice five, which allows the player to roll the dice and move forward
bool menu5(Board _board, int currentPlayerIndex, int vec, int arr[])
{
    cout << endl;
    //"Roll the dice" which generates a number from 1-6
    int rollDice = rand() % 6 + 1;
    // Display the rolled number
    cout << "Rolling dice..." << endl;
    cout << "You rolled a " << rollDice << "!" << endl;
    cout << endl;
    // Add rolled number to the player's position
    arr[currentPlayerIndex] += rollDice;

    // If the player has reached the last tile, display they have reached pride rock
    if (arr[currentPlayerIndex] >= 51)
    {
        _board.movePlayer(currentPlayerIndex, 51);
        if (vec == 1)
        {
            _board.displayPrideTrack(currentPlayerIndex);
        }
        else if (vec == 2)
        {
            _board.displayTrainTrack(currentPlayerIndex);
        }
        cout << "You have reached the Pride Rock!" << endl;
        return true;
    }
    // Else, move the player depending on their position and display their correct path
    else
    {
        _board.movePlayer(currentPlayerIndex, arr[currentPlayerIndex]);
        if (vec == 1)
        {
            _board.displayPrideTrack(currentPlayerIndex);
        }
        else if (vec == 2)
        {
            _board.displayTrainTrack(currentPlayerIndex);
        }
        cout << "color of tile: " << _board.determineColor(currentPlayerIndex, vec, arr[currentPlayerIndex]) << endl;
        return false;
    }
    return false;
}

// Hyena Tile, lose 100 stamina and strength, player must go back three spaces. Written by Donna
void brownTile(Board _board, int currentPlayerIndex, int vec, int arr[])
{
    cout << "Oh no! You are now in land of Hyenas! You have lost (-100) Stamina and Strength points while fighting Hyenas! You have ran back three tiles to survive!" << endl;

    if (arr[currentPlayerIndex] < 3)
    {
        _board.movePlayer(currentPlayerIndex, arr[currentPlayerIndex] - arr[currentPlayerIndex]);
        arr[currentPlayerIndex] = 0;
    }
    else
    {
        arr[currentPlayerIndex] = arr[currentPlayerIndex] - 3;
        _board.movePlayer(currentPlayerIndex, arr[currentPlayerIndex]);
    }

    if (vec == 1)
    {
        _board.displayPrideTrack(currentPlayerIndex);
    }
    else if (vec == 2)
    {
        _board.displayTrainTrack(currentPlayerIndex);
    }
    cout << "color of tile: " << _board.determineColor(currentPlayerIndex, vec, arr[currentPlayerIndex]) << endl;

    // if (_board.determineColor(currentPlayerIndex, vec, arr[currentPlayerIndex]) == 'N')
    // {
    //     return true;
    // }
    // return false;
}

// Oasis Tile, returns 100. Written by Joanne
int blueTile()
{
    return 100;
}

// Advisor Tile, allows user to choose a new advisor or stick with their current one. Only applicable for Cub Training Tile. Written by Joanne
int pinkTile(string advisors[], string chosenAdvisors[], int currentPlayerIndex, Player currentPlayer)
{
    // Create string for current advisor
    string currentAdvisor;
    // Create bool to evaluate whether valid advisor within list
    bool validAdvisor = false;
    // Call display advisors
    displayAdvisors("advisors.txt", advisors);
    // Output to user the tile type, who their current advisor is, and how to choose a new one or skip this decision
    cout << "You landed on an advisor tile!" << endl
         << "Your current advisor: " << chosenAdvisors[currentPlayerIndex] << endl
         << "You may change your advisor or choose to skip. Choosing a new advisor will cost 300 pride points." << endl;
         cout << "Your current pride points: " << currentPlayer.getPride() << endl;
    cout << "Please enter the name of the advisor you wish to choose. If you wish to skip, please enter \"Skip\"" << endl;
    cin >> currentAdvisor;

    // If choose to skip, end the function
    if (currentAdvisor == "Skip")
    {
        validAdvisor = true;
        cout << "Your Pride Points: " << endl << currentPlayer.getPride() << " -> ";
        return 0;
    }

    // Loop to compare the user input with the list of valid advisors
    for (int k = 0; k < 5; k++)
    {
        // If it is a valid advisor...
        if (currentAdvisor == advisors[k])
        {
            // If the inputted advisor is already their advisor...
            if (currentAdvisor == chosenAdvisors[currentPlayerIndex])
            {
                // Output that the user already has that advisor. Prompt them to choose a new one or skip
                do
                {
                    cout << "You already have that advisor. Please enter a different one or type \"Skip\" to skip." << endl;
                    cin >> currentAdvisor;
                    if (currentAdvisor == "Skip")
                    {
                        validAdvisor = true;
                        cout << "Your Pride Points: " << endl << currentPlayer.getPride() << " -> ";
                        return 0;
                    }
                } while (currentAdvisor == chosenAdvisors[currentPlayerIndex]);
            }
            // Change the advisor of the player to the new one
            chosenAdvisors[currentPlayerIndex] = currentAdvisor;
            validAdvisor = true;
            // The amount of pride points subtracted is 300.
            cout << "Your Pride Points: " << endl << currentPlayer.getPride() << " -> ";
            return -300;
        }
    }

    // If the character the user entered is invalid prompt user to enter the name until one matches
    if (validAdvisor == false)
    {
        do
        {
            cout << "Invalid advisor. Please enter the name of the advisor correctly or type \"Skip\" to skip." << endl;
            cin >> currentAdvisor;

            // If choose to skip, end the function
            if (currentAdvisor == "Skip")
            {
                validAdvisor = true;
                cout << "Your Pride Points: " << endl << currentPlayer.getPride() << " -> ";
                return 0;
            }

            // Loop to compare the user input with the list of valid advisors
            for (int k = 0; k < 5; k++)
            {
                // If it is a valid advisor...
                if (currentAdvisor == advisors[k])
                {
                    // If the inputted advisor is already their advisor...
                    if (currentAdvisor == chosenAdvisors[currentPlayerIndex])
                    {
                        // Output that the user already has that advisor. Prompt them to choose a new one or skip
                        do
                        {
                            cout << "You already have that advisor. Please enter a different one or type \"Skip\" to skip." << endl;
                            cin >> currentAdvisor;
                            if (currentAdvisor == "Skip")
                            {
                                validAdvisor = true;
                                cout << "Your Pride Points: " << endl << currentPlayer.getPride() << " -> ";
                                return 0;
                            }
                        } while (currentAdvisor == chosenAdvisors[currentPlayerIndex]);
                    }
                    // Change the advisor of the player to the new one
                    chosenAdvisors[currentPlayerIndex] = currentAdvisor;
                    validAdvisor = true;
                }
            }
        } while (validAdvisor == false);
    }
    // The amount of pride points subtracted is 300.
    cout << "Your Pride Points: " << endl << currentPlayer.getPride() << " -> ";
    return -300;
}

// Random Event Tile, chooses a random event that may only be bypassed with a certain amount of leadership points. Advisor choice
// also plays a big part in how events may be bypassed or affected. Written by Joanne
int greenTile(string chosenAdvisors[], int currentPlayerIndex, string filename, Player currentPlayer)
{
    // String variable to store full line of text
    string fullLine;
    // Vectors to store each part of the line of text into description, strength requirement, stamina requirement, wisdom requirement
    // and amount of pride points gained or lost from the specific event
    vector<string> eventDesc;
    vector<int> strengthReq;
    vector<int> staminaReq;
    vector<int> wisdomReq;
    vector<int> pridePoints;
    // Reroll variables
    string reroll1;
    int reroll;

    // Open file and make sure it opens
    ifstream fileIn(filename);
    if (fileIn.fail())
    {
        return 0;
    }

    // Skip first line
    getline(fileIn, fullLine);

    // Split each line and print the stats of each lion character
    while (getline(fileIn, fullLine))
    {

        string arr1[6] = {};
        split(fullLine, '|', arr1, 6);

        // Add each part into corresponding vector
        eventDesc.push_back(arr1[1]);
        strengthReq.push_back(stoi(arr1[2]));
        staminaReq.push_back(stoi(arr1[3]));
        wisdomReq.push_back(stoi(arr1[4]));
        pridePoints.push_back(stoi(arr1[5]));
    }

    // Close file
    fileIn.close();

    // Output to user
    cout << "You landed on an event tile!" << endl;

    // Choose a random number between 1-10, which chooses a random event
    // Then, output to user the event description and gain or loss of pride points
    int eventNumber = rand() % 10;
    switch (eventNumber)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        cout << "Event: " << eventDesc[eventNumber] << "(" << pridePoints[eventNumber] << ")" << endl;
        break;
    }

    // If the player's advisor is Zazu (a chance to reroll event)...
    if (chosenAdvisors[currentPlayerIndex] == "Zazu")
    {

        cout << "Your advisor is Zazu, meaning that you have a chance to reroll this event. Type 1 to reroll and 0 to cancel." << endl;

        while (true)
        {

            if (cin >> reroll1 && isValidInt(reroll1) == true && (stoi(reroll1) == 0 || stoi(reroll1) == 1))
            {
                reroll = stoi(reroll1);
                break;
            }
            else
            {
                cout << "Invalid number. Type 1 to reroll and 0 to cancel." << endl;
                cin.clear();  // reset the failbit
                cin.ignore(); // discard the invalid input
            }
        }

        if (reroll == 1)
        {
            eventNumber = rand() % 10;
            switch (eventNumber)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                cout << "Event: " << eventDesc[eventNumber] << "(" << pridePoints[eventNumber] << ")" << endl;
                break;
            }
        }
    }

    int playerStrength = currentPlayer.getStrength();
    int playerStamina = currentPlayer.getStamina();
    int playerWisdom = currentPlayer.getWisdom();

    if (eventNumber < 6)
    {
        if (playerStrength >= strengthReq[eventNumber] && playerStamina >= staminaReq[eventNumber] && playerWisdom >= wisdomReq[eventNumber])
        {
            cout << "You had enough strength/stamina/wisdom points to successfully bypass this negative event!" << endl
                 << "You gained 100 pride points" << endl;
            pridePoints[eventNumber] = 100;
        }
        else if (chosenAdvisors[currentPlayerIndex] == "Rafiki")
        {
            cout << "Your advisor is Rafiki, meaning that you have a chance of bypassing this negative event." << endl
                 << "Generating..." << endl;

            int bypassNum = rand() % 3;
            cout << bypassNum << endl;
            switch (bypassNum)
            {
            case 0:
            case 1:
                cout << "Unfortunately, you did not bypass this event." << endl;
                break;
            case 2:
                cout << "Congrats! You succesfully bypassed this event." << endl;
                pridePoints[eventNumber] = 0;
                break;
            }
        }
        else if (chosenAdvisors[currentPlayerIndex] == "Sarabi")
        {
            cout << "Your advisor is Sarabi, meaning that you will lose less pride points from this negative event." << endl;
            int newLoss = pridePoints[eventNumber] + -1 * (pridePoints[eventNumber] / 4);
            cout << "You would originally lose " << pridePoints[eventNumber] << ", but because your advisor is Sarabi, " << "you will only lose " << newLoss << " pride points from this negative event." << endl;
            pridePoints[eventNumber] = newLoss;
        }
    }
    else if (eventNumber >= 6)
    {
        if (chosenAdvisors[currentPlayerIndex] == "Sarafina")
        {
            cout << "Your advisor is Sarafina, meaning that you will gain a boost in pride points from this positive event." << endl;
            int newGain = pridePoints[eventNumber] + (pridePoints[eventNumber] / 4);
            cout << "You would originally gain " << pridePoints[eventNumber] << ", but because your advisor is Sarafina, " << "you will gain " << newGain << " pride points from this positive event." << endl;
            pridePoints[eventNumber] = newGain;
        }
    }

    // cout << "pride: " << pridePoints[eventNumber] << endl;
    return pridePoints[eventNumber];
}

bool purpleTile(string filename){
    string fullLine;
    vector<string> question;
    vector<string> correctAnswer;

        // Open file and make sure it opens
    ifstream fileIn(filename);
    if (fileIn.fail())
    {
        return 0;
    }

    // Skip first line
    getline(fileIn, fullLine);

    // Split each line and print the stats of each lion character
    while (getline(fileIn, fullLine))
    {

        string arr1[3] = {};
        split(fullLine, '|', arr1, 3);

        // Add each part into corresponding vector
        question.push_back(arr1[1]);
        correctAnswer.push_back(arr1[2]);
    }

    // Close file
    fileIn.close();

    cout << "It's time to check your wisdom! " << endl;

    srand(time(0));
    
    int riddle = rand() % 10;
    string answer;

    switch(riddle){
        case 0:
        case 1:
        case 2:   
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            cout << question[riddle] << " (Exclude 'The' 'A' or 'An' from your answer and write your answer in all lowercase)" << endl;
            cin >> answer;
            if(answer == correctAnswer[riddle]){
                return true;
            }
            break;
    }

    return false;
}

int redTile(Board _board, int currentPlayerIndex, int vec, int arr[]){

    string choice;

    cout << "You have stumbled accross a land of brave contract. You can either choose to have an advisor or gain (+500) Stamina, Strength, Wisdom Points and Pride Points. " << endl;
    cout << "However, you will move back 10 tiles for choosing either option. Press 0 to move on, press 1 to choose an advisor or press 2 to gain (+500) Stamina, Strength, Wisdom Points and Pride Points. " << endl;

    cin >> choice;

    while(isValidInt(choice) == false || (stoi(choice) != 0 && stoi(choice) != 1 && stoi(choice) != 2)){
        cin.clear();  // reset the failbit
        cin.ignore(); // discard the invalid input
        cout << "Invalid choice, please enter 0, 1 or 2." << endl;
        cin >> choice;

    }

    if(stoi(choice) == 1 || stoi(choice) == 2){
        if (arr[currentPlayerIndex] < 10)
        {
            _board.movePlayer(currentPlayerIndex, arr[currentPlayerIndex] - arr[currentPlayerIndex]);
            arr[currentPlayerIndex] = 0;
        }
        else
        {
            arr[currentPlayerIndex] = arr[currentPlayerIndex] - 10;
            _board.movePlayer(currentPlayerIndex, arr[currentPlayerIndex]);
        }

        if (vec == 1)
        {
            _board.displayPrideTrack(currentPlayerIndex);
        }
        else if (vec == 2)
        {
            _board.displayTrainTrack(currentPlayerIndex);
        }
        cout << "color of tile: " << _board.determineColor(currentPlayerIndex, vec, arr[currentPlayerIndex]) << endl;
    }
    
    return stoi(choice);
}

// Function that converts leadership points to pride points
// For every 100 leadership points, player gains 1,000 pride points
int convertLeadershipPoints(Player currentPlayer){
    int strength, stamina, wisdom, total;
    strength = currentPlayer.getStrength();
    stamina = currentPlayer.getStamina();
    wisdom = currentPlayer.getWisdom();
    total = strength + stamina + wisdom;
    total /= 100;
    total *= 1000;
    cout << total << endl;
    return total;
}