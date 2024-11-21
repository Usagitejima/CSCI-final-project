//Donna and Joanne

#include "Player.h"

//Default constructor
Player::Player(){
    _name = "";
    _age = 1;
    _stamina = 100;
    _strength = 100;
    _wisdom = 100;
    _pride_points = 0;
}

//Constructor with parameters, make sure values are within the limit
Player::Player(string name, int strength, int stamina, int wisdom){
    _name = name;
    _age = 1;
    _pride_points = 0;

    if(stamina < 100 || stamina > 1000){
        _stamina = 100;
    }
    else{
        _stamina = stamina;
    }
    
    if(strength < 100 || strength > 1000){
        _strength = 100;
    }
    else{
        _strength = strength;
    }
    
    if(wisdom < 100 || wisdom > 1000){
        _wisdom = 100;
    }
    else{
        _wisdom = wisdom;
    }
    
}

//Get commands that return each value of the class
string Player::getName(){
    return _name;
}

int Player::getStrength(){
    return _strength;
}

int Player::getStamina(){
    return _stamina;
}

int Player::getWisdom(){
    return _wisdom;
}

int Player::getPride(){
    return _pride_points;
}

int Player::getAge(){
    return _age;
}

//Set commands that sets the specific values
void Player::setName(string name){
    _name = name;
}

void Player::setStrength(int strength){
    _strength = strength;
}

void Player::setStamina(int stamina){
    _stamina = stamina;
}

void Player::setWisdom(int wisdom){
    _wisdom = wisdom;
}

void Player::setPride(int pride){
    _pride_points = pride;
}
void Player::setAge(int age){
    _age = age;
}

//Add commands for adding values
void Player::addStrength (int strength){
    _strength += strength;
}
void Player::addStamina (int stamina){
    _stamina += stamina;
}
void Player::addWisdom (int wisdom){
    _wisdom += wisdom;
}
void Player::addPridePoints (int pride_points){
    _pride_points += pride_points;
}
void Player::addAge (int age){
    _age += age;
}

//Choosing to train the cub which adds strength, stamina, and wisdom
//However, subtracts pride points
void Player::trainCub(int strength, int stamina, int wisdom){
    addPridePoints(-5000);
    addStamina(1000);
    addStrength(1000);
    addWisdom(1000);
}

//Choosing to go to pride lands directly which substracts strength, stamina, and wisdom
//However, adds pride points
void Player::toPrideLands(){
    addPridePoints(5000);
    addStamina(-1000);
    addStrength(-2000);
    addWisdom(-2000);
}

//Prints the stats of the player
void Player::printStats(){
    cout << "#~#~#~#~#~#~#~#" << endl;
    cout << _name << ", age " << _age << endl;
    cout << "Strength: " << _strength << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Wisdom: " << _wisdom << endl;
    cout << "Pride Points: " << _pride_points << endl;
    cout << "#~#~#~#~#~#~#~#" << endl;
}