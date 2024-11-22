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

    void Tile::Brown(Player _player){
        _player.addStamina(-300);
        // 1. Moves back one tile
    }
    
    void Tile::Purple(Player _player){
        // 1. Facing a riddle
    }

    void Tile::Orange(Player _player){
        /*
        1. For every 100 points in Stamina, Strength and Wisdom points, add 1000 pride points to the player's Pride Points total. 
        2. After all players reach the orange tile, print out everyone's stats and announce the winner based on the amounts of pride points.
        3. Sort each player seperately by their Stamina, Strength and Wisdom points. 
        */
    }

    void Tile::Grey(Player _player){
        // 1. Starting point of the game. 
    }

    char Tile::determineColor(){
        // 1. Based on position of the player, determine the color of the tile that the player is on
    }