//Donna and Joanne

#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Player.h"

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _prideTiles[4][_BOARD_SIZE];
    Tile _trainTiles[4][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 4;
    int _player_count;
    int _player_position[_MAX_PLAYERS];
    void displayPrideTile(int player_index, int pos);
    void displayTrainTile(int player_index, int pos);
    void initializePrideTiles(int player_index);
    void initializeTrainTiles(int player_index);
    bool isPlayerOnTile(int player_index, int pos);

public:
    Board();
    Board(int player_count);
    void displayPrideTrack(int player_index);
    void displayTrainTrack(int player_index);
    void initializePrideBoard();
    void initializeTrainBoard();
    void displayPrideBoard();
    void displayTrainBoard();
    bool movePlayer(int player_index, int diceAmount);
    int getPlayerPosition(int player_index) const;

    //Function to determine which color the tile is that the player is currently on
    char determineColor(int player_index, int pathType, int pos);
};

#endif
