// Donna and Joanne

#include "Tile.h"
Tile::Tile(){
    color = 'G';
}

Tile::Tile(char tileColor){
    color = tileColor; 
}

char Tile::getColor(){
    return color;
}

string Tile::getEffect(){
    return effects;
}

void Tile::setColor(char Color){
    color = Color;
}

void Tile::setEffects(string Effects){
    effects = Effects;
}