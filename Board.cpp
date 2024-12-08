// Donna and Joanne

#include "Board.h"

#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

//Initializes the board that leads player straight to the pride lands. Written by Donna
void Board::initializePrideBoard()
{
    // Seed random number generator in your main function once
    // for (int i = 0; i < 4; i++)
    // {
        initializePrideTiles(); // This ensures each lane has a unique tile distribution
    // }
}

//Initializes the board that leads player to cub training. Written by Donna
void Board::initializeTrainBoard()
{
    // Seed random number generator in your main function once
    // for (int i = 0; i < 4; i++)
    // {
        initializeTrainTiles(); // This ensures each lane has a unique tile distribution
    // }
}

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void Board::initializePrideTiles()
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        }
        else if (i == 0)
        {
            temp.color = 'Y';
        }
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count))
        {
            if (i > 30)
            {
                int color_choice = rand() % 6 + 1;
                switch (color_choice)
                {
                // case 0:
                //     temp.color = 'B'; // Blue
                //     break;
                // case 1:
                //     temp.color = 'N'; // Brown
                //     break;
                // case 2:
                //     temp.color = 'U'; // Purple
                //     break;
                // case 3:
                // case 4:
                // case 5:
                case 6:
                    temp.color = 'R'; // Green
                    green_count++;
                    break;
                }
            }
            else
            {
                temp.color = 'R';
                green_count++;
            }
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            int color_choice = rand() % 4;
            switch (color_choice)
            {
            // case 0:
            //     temp.color = 'B'; // Blue
            //     break;
            // case 1:
            //     temp.color = 'N'; // Brown
            //     break;
            case 2:
                temp.color = 'R'; // Red
                break;
            // case 3:
            //     temp.color = 'U'; // Purple
            //     break;
            }
        }

        // Assign the tile to the board for the specified lane
        _prideTiles[i] = temp;
    }
}

void Board::initializeTrainTiles()
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        }
        else if (i == 0)
        {
            temp.color = 'Y';
        }
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count))
        {
            if (i < 30)
            {
                temp.color = 'G';
                green_count++;
            }
            else
            {
                int color_choice = rand() % 7;
                switch (color_choice)
                {
                case 0:
                    temp.color = 'B'; // Blue
                    break;
                // case 1:
                //     temp.color = 'P'; // Pink
                //     break;
                case 2:
                    temp.color = 'N'; // Brown
                    break;
                case 3:
                    temp.color = 'U'; // Purple
                    break;
                case 4:
                case 5:
                case 6:
                    temp.color = 'G'; // Green
                    break;
                }
            }
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            int color_choice = rand() % 4;
            switch (color_choice)
            {
            case 0:
                temp.color = 'B'; // Blue
                break;
            // case 1:
            //     temp.color = 'P'; // Pink
            //     break;
            case 2:
                temp.color = 'N'; // Brown
                break;
            case 3:
                temp.color = 'U'; // Purple
                break;
            }
        }

        // Assign the tile to the board for the specified lane
        _trainTiles[i] = temp;
    }
}

// Default constructor
Board::Board()
{
    _player_count = 1;

    // Initialize player position
    _player_position[0] = 0;

    // Initialize tiles
    initializePrideBoard();
    initializeTrainBoard();
}

// Constructor with parameters
Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }

    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }

    // Initialize tiles

    initializePrideBoard();
    initializeTrainBoard();
}

// Returns true if the player is on the specific tile
bool Board::isPlayerOnTile(int player_index, int pos)
{
    if (_player_position[player_index] == pos)
    {
        return true;
    }
    return false;
}

// Prints out tile
void Board::displayPrideTile(int player_index, int pos)
{
    string space = "                                       ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    if (_prideTiles[pos].color == 'R')
    {
        color = RED;
    }
    else if (_prideTiles[pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_prideTiles[pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_prideTiles[pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_prideTiles[pos].color == 'N')
    {
        color = BROWN;
    }
    // else if (_prideTiles[player_index][pos].color == 'P')
    // {
    //     color = PINK;
    // }
    else if (_prideTiles[pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_prideTiles[pos].color == 'Y')
    {
        color = GREY;
    }

    if (player == true)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

// Prints out tile
void Board::displayTrainTile(int player_index, int pos)
{
    string space = "                                       ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    // if (_trainTiles[player_index][pos].color == 'R')
    // {
    //     color = RED;
    // }
    if (_trainTiles[pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_trainTiles[pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_trainTiles[pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_trainTiles[pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_trainTiles[pos].color == 'P')
    {
        color = PINK;
    }
    else if (_trainTiles[pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_trainTiles[pos].color == 'Y')
    {
        color = GREY;
    }

    if (player == true)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

// Displays the player on a tile
void Board::displayPrideTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayPrideTile(player_index, i);
    }
    cout << endl;
}

//
void Board::displayPrideBoard()
{
    for (int i = 0; i < 1; i++)
    {
        displayPrideTrack(i);
        if (i == 0)
        {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}

// Displays the player on a tile
void Board::displayTrainTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTrainTile(player_index, i);
    }
    cout << endl;
}

//
void Board::displayTrainBoard()
{
    for (int i = 0; i < 1; i++)
    {
        displayTrainTrack(i);
        if (i == 0)
        {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}

bool Board::movePlayer(int player_index, int diceAmount)
{
    // Increment player position
    _player_position[player_index] += diceAmount;
    if (_player_position[player_index] == _BOARD_SIZE - 1)
    {
        // Player reached last tile
        return true;
    }
    return false;
}

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}

char Board::determineColor(int player_index, int pathType, int pos)
{
    // 1. Based on position of the player, determine the color of the tile that the player is on
    // 2. This will create and use an array to track the colors within the Board class
    // 3. Then, it will be used to determine the current tile color
    if (pathType == 1){
        return _prideTiles[pos].color;
    }
    else if (pathType == 2){
        return _trainTiles[pos].color;
    }
    return 'M';
}