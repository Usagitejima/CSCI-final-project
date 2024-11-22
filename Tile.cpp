// Donna and Joanne

#include "Tile.h"

    void Tile::Green(Player _player){
        /*
        1. Determine whether to trigger a random event (50% chance of triggering)
        2. If triggered, choose from a random event (riddles, challenges, etc.)
        3. Run the event and update player skill points based on events
        */
    }

    void Tile::Pink(Player _player){
        _player.addStamina(300);
        _player.addStrength(300);
        _player.addWisdom(300);
        // 1. The player gets an option to choose an advisor
        // 2. If the player already has an advisor, allow them to switch to a different one if wanted
    }

    void Tile::Red(Player _player){
        _player.addStamina(-100);
        _player.addWisdom(-100);
        _player.addStrength(-100);
        // 1. Also implement moving the player back 10 tiles
    }

    void Tile::Blue(Player _player){
        _player.addStamina(200);
        _player.addWisdom(200);
        _player.addStrength(200);
    }

    void Brown(Player _player);
    void Purple(Player _player);
    void Orange(Player _player);
    void Grey(Player _player);

    char Tile::determineColor(){
        // 1. Based on position of the player, determine the color of the tile that the player is on
    }