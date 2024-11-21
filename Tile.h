//Donna and Joanne

#ifndef TILE_H
#define TILE_H

#include <iostream>
using namespace std;

class Tile
{
    private:
        char color;
        string effects;

    public:
        Tile();
        Tile(char);

        char getColor();
        string getEffect();
        
        void setColor(char);
        void setEffects(string);
        
};

#endif