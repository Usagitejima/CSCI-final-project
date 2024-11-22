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

void Board::initializeBoard()
{
    // Seed random number generator in your main function once
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i); // This ensures each lane has a unique tile distribution
    }
}

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void Board::initializeTiles(int player_index)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    srand(time(0));

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
            temp.color = 'G';
            green_count++;
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            int color_choice = rand() % 5;
            switch (color_choice)
            {
            case 0:
                temp.color = 'B'; // Blue
                break;
            case 1:
                temp.color = 'P'; // Pink
                break;
            case 2:
                temp.color = 'N'; // Brown
                break;
            case 3:
                temp.color = 'R'; // Red
                break;
            case 4:
                temp.color = 'U'; // Purple
                break;
            }
        }

        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}

// Default constructor
Board::Board()
{
    _player_count = 1;

    // Initialize player position
    _player_position[0] = 0;

    // Initialize tiles
    initializeBoard();
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

    initializeBoard();
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
void Board::displayTile(int player_index, int pos)
{
    // string space = "                                       ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);
    // char tileColors[52];
    // int tileCount = 0;

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    if (_tiles[player_index][pos].color == 'R')
    {
        color = RED;
        // tileColors[tileCount] = _tiles[player_index][pos].color;
        // tileCount++;
    }
    else if (_tiles[player_index][pos].color == 'G')
    {
        color = GREEN;
        // tileColors[tileCount] = _tiles[player_index][pos].color;
        // tileCount++;
    }
    else if (_tiles[player_index][pos].color == 'B')
    {
        color = BLUE;
        // tileColors[tileCount] = _tiles[player_index][pos].color;
        // tileCount++;
    }
    else if (_tiles[player_index][pos].color == 'U')
    {
        color = PURPLE;
        // tileColors[tileCount] = _tiles[player_index][pos].color;
        // tileCount++;
    }
    else if (_tiles[player_index][pos].color == 'N')
    {
        color = BROWN;
        // tileColors[tileCount] = _tiles[player_index][pos].color;
        // tileCount++;
    }
    else if (_tiles[player_index][pos].color == 'P')
    {
        color = PINK;
        // tileColors[tileCount] = _tiles[player_index][pos].color;
        // tileCount++;
    }
    else if (_tiles[player_index][pos].color == 'O')
    {
        color = ORANGE;
        // tileColors[tileCount] = _tiles[player_index][pos].color;
        // tileCount++;
    }
    else if (_tiles[player_index][pos].color == 'Y')
    {
        color = GREY;
        // tileColors[tileCount] = _tiles[player_index][pos].color;
        // tileCount++;
    }

    if (player == true)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }

    // tileCount++;

}

// Displays the player on a tile
void Board::displayTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_index, i);
    }
    cout << endl;
}

//
void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0)
        {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}

bool Board::movePlayer(int player_index)
{
    // Increment player position
    _player_position[player_index]++;
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

char Board::determineColor()
{
    // 1. Based on position of the player, determine the color of the tile that the player is on
    // 2. This will create and use an array to track the colors within the Board class
    // 3. Then, it will be used to determine the current tile color
    return 'H';
}