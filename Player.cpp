// Donna and Joanne

#include "Player.h"

// Default constructor
Player::Player()
{
    _name = "";
    _age = 1;
    _stamina = 100;
    _strength = 100;
    _wisdom = 100;
    _pride_points = 0;
}

// Constructor with parameters, make sure values are within the limit
Player::Player(string name, int strength, int stamina, int wisdom)
{
    _name = name;
    _age = 1;
    _pride_points = 0;

    if (stamina < 100 || stamina > 1000)
    {
        _stamina = 100;
    }
    else
    {
        _stamina = stamina;
    }

    if (strength < 100 || strength > 1000)
    {
        _strength = 100;
    }
    else
    {
        _strength = strength;
    }

    if (wisdom < 100 || wisdom > 1000)
    {
        _wisdom = 100;
    }
    else
    {
        _wisdom = wisdom;
    }
}

// Get commands that return each value of the class
string Player::getName()
{
    return _name;
}

int Player::getStrength()
{
    return _strength;
}

int Player::getStamina()
{
    return _stamina;
}

int Player::getWisdom()
{
    return _wisdom;
}

int Player::getPride()
{
    return _pride_points;
}

int Player::getAge()
{
    return _age;
}

// Set commands that sets the specific values
void Player::setName(string name)
{
    _name = name;
}

void Player::setStrength(int strength)
{
    _strength = strength;
}

void Player::setStamina(int stamina)
{
    _stamina = stamina;
}

void Player::setWisdom(int wisdom)
{
    _wisdom = wisdom;
}

void Player::setPride(int pride)
{
    _pride_points = pride;
}
void Player::setAge(int age)
{
    _age = age;
}

// Add commands for adding values
void Player::addStrength(int strength)
{
    _strength += strength;
}
void Player::addStamina(int stamina)
{
    _stamina += stamina;
}
void Player::addWisdom(int wisdom)
{
    _wisdom += wisdom;
}
void Player::addPridePoints(int pride_points)
{
    _pride_points += pride_points;
}
void Player::addAge(int age)
{
    _age += age;
}

// Choosing to train the cub which adds strength, stamina, and wisdom
// However, subtracts pride points
void Player::trainCub()
{
    addPridePoints(-5000);
    addStamina(500);
    addStrength(500);
    addWisdom(1000);
}

// Choosing to go to pride lands directly which substracts strength, stamina, and wisdom
// However, adds pride points
void Player::toPrideLands()
{
    addPridePoints(5000);
    addStamina(200);
    addStrength(200);
    addWisdom(200);
}

// Prints the stats of the player
void Player::printStats()
{
    cout << "#~#~#~#~#~#~#~#" << endl;
    cout << _name << ", age " << _age << endl;
    cout << "Strength: " << _strength << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Wisdom: " << _wisdom << endl;
    cout << "Pride Points: " << _pride_points << endl;
    cout << "#~#~#~#~#~#~#~#" << endl;
}

void Player::Green()
{
    /*
    1. Determine whether to trigger a random event (50% chance of triggering)
    2. If triggered, choose from a random event (riddles, challenges, etc.)
    3. Run the event and update player skill points based on events
    */
}

void Player::Pink()
{
    addStamina(300);
    addStrength(300);
    addWisdom(300);
    // 1. The player gets an option to choose an advisor
    // 2. If the player already has an advisor, allow them to switch to a different one if wanted
}

void Player::Red()
{
    addStamina(-100);
    addWisdom(-100);
    addStrength(-100);
    // 1. Also implement moving the player back 10 tiles
}

void Player::Blue()
{
    addStamina(200);
    addWisdom(200);
    addStrength(200);
}

void Player::Brown()
{
    addStamina(-300);
    // 1. Moves back one tile
}

void Player::Purple()
{
    // 1. Facing a riddle
}

void Player::Orange()
{
    /*
    1. For every 100 points in Stamina, Strength and Wisdom points, add 1000 pride points to the player's Pride Points total.
    2. After all players reach the orange tile, print out everyone's stats and announce the winner based on the amounts of pride points.
    3. Sort each player seperately by their Stamina, Strength and Wisdom points.
    */
}

void Player::Grey()
{
    // 1. Starting point of the game.
}

//This function sets the stats of the player according to the character they chose
void Player::setStats(string filename, string chosenChar)
{

    string fullLine;

    ifstream fileIn(filename);
    if (fileIn.fail())
    {
        return;
    }

    while (getline(fileIn, fullLine))
    {
        string arr[6];

        string word;
        int j = 0, k = 0;

        // If there is nothing to split, return 0
        if (fullLine.length() == 0)
        {
            return;
        }

        // Loop to go through the whole line
        for (unsigned int i = 0; i < fullLine.length(); i++)
        {
            // If there is a '|' found, put the word into the array
            if (fullLine[i] == '|')
            {
                arr[j] = word;
                word = "";
                j++;
                continue;
            }
            else if (j == 6)
            {
                k++;
                break;
            }
            // Keep adding characters into the word until it hits a delim
            else
            {
                word += fullLine[i];
            }
        }

        // Add remaining word to array
        arr[j] = word;

        if (arr[0] == chosenChar)
        {
            setAge(stoi(arr[1]));
            setStrength(stoi(arr[2]));
            setStamina(stoi(arr[3]));
            setWisdom(stoi(arr[4]));
            setPride(stoi(arr[5]));
        }
    }
}
