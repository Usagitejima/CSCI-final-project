// Donna and Joanne

#include "Tile.h"

    // void Tile::Green(_player){
    //     //random events (50% chance of triggering)
    // }

    void Tile::Pink(Player _player){
        _player.addStamina(300);
        _player.addStrength(300);
        _player.addWisdom(300);
        //also able to choose your advisor
    }

    // void Tile::Red(){
    //     _player.addStamina(-100);
    //     _player.addWisdom(-100);
    //     _player.addStrength(-100);
    //     //move back 10 tiles
    // }

    // void Tile::Blue(){
    //     _player.addStamina(200);
    //     _player.addWisdom(200);
    //     _player.addStrength(200);
    // }

    char Tile::determineColor(char tileColors[]){
        for (int i = 0; i < 52; i++){
            cout << tileColors[i] << endl;
        }
        return 'H';
    }