//Donna and Joanne

#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Player.h"

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    int _player_position[_MAX_PLAYERS];
    void displayTile(int player_index, int pos);
    void initializeTiles(int player_index);
    bool isPlayerOnTile(int player_index, int pos);

public:
    Board();
    Board(int player_count);
    void displayTrack(int player_index);
    void initializeBoard();
    void displayBoard();
    bool movePlayer(int player_index);
    int getPlayerPosition(int player_index) const;

    //Function to determine which color the tile is that the player is currently on
    char determineColor();
};

#endif
