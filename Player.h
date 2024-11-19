#include <iostream>
using namespace std;

class Player{
    private:
        string _name;
        int _strength, _stamina, _wisdom, _pride_points, _age;
    public:
        Player();
        Player(string, int, int, int);

        string getName();
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPride();
        int getAge();

        void setName(string);
        void setStrength(int);
        void setStamina(int);
        void setWisdom(int);
        void setPride(int);
        void setAge(int);

        void addStrength (int strength);
        void addStamina (int stamina);
        void addWisdom (int wisdom);
        void addPridePoints (int pride_points);
        void addAge (int age);

        void trainCub(int, int, int);
        void toPrideLands();
        void printStats();
};