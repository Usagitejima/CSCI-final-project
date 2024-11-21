// Donna and Joanne

#ifndef TILE_H
#define TILE_H



#include <iostream>
#include "Player.h"
using namespace std;

struct Tile
{
    char color;
    string effects;

    // void Green(Player _player);
    void Pink(Player _player);
    // void Red();
    // void Blue();

    char determineColor(char tileColors[]);
};

#endif