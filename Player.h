#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Board.h"
#include "Tile.h"

using namespace std;

class Player{
    private:
        //Private values of player class
        string _name;
        int _strength, _stamina, _wisdom, _pride_points, _age;
    public:
        //Default and parameterized constructors
        Player();
        Player(string, int, int, int);

        //Getter functions
        string getName();
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPride();
        int getAge();

        //Setter functions
        void setName(string);
        void setStrength(int);
        void setStamina(int);
        void setWisdom(int);
        void setPride(int);
        void setAge(int);

        //Functions that add points
        void addStrength (int strength);
        void addStamina (int stamina);
        void addWisdom (int wisdom);
        void addPridePoints (int pride_points);
        void addAge (int age);

        //Functions to choose path type and to print stats of the player
        void trainCub(int, int, int);
        void toPrideLands();
        void printStats();
};

#endif