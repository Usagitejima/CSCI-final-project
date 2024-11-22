// Donna and Joanne

#ifndef TILE_H
#define TILE_H

#include <iostream>
#include "Player.h"
using namespace std;

struct Tile
{
    char color;

    //The functions that are run based on the current color tile the player is on
    void Green(Player _player);
    void Pink(Player _player);
    void Red(Player _player);
    void Blue(Player _player);
    void Brown(Player _player);
    void Purple(Player _player);
    void Orange(Player _player);
    void Grey(Player _player);

    //Function to determine which color the tile is that the player is currently on
    char determineColor();
};

#endif