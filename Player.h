#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>

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

        //The functions that are run based on the current color tile the player is on
        void Green();
        void Pink();
        void Red();
        void Blue();
        void Brown();
        void Purple();
        void Orange();
        void Grey();

        //Function to set the stats of the player based on what character they choose. Written by Joanne
        void setStats(string filename, string chosenChar);

};

#endif