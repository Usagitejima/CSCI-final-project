// Donna and Joanne

//include all header files
#include "Board.h"
#include "Player.h"
#include "Tile.h"

int main(){

    /*
    1. Ask the user how many players will be playing the game
    2. Update board class with information based on the number of players
    3. Display to terminal all available characters and their stats
    4. Ask player for their name and to select a character and path type
    5. Repeat for remaining players
    6. Game should start and boards should be displayed for each player
    7. Players should be able to see a main menu on their turn that allows them to:
        - Review Pride Point and Leadership Trait stats.
        - Check your character name and age.
        - Display board to view current position.
        - Check who your current advisor is on the game.
        - Move Forward
    8. Code should repeat for each player
    */

    // Code to create a new player and print stats
    // Checks whether printing stats and adding stats work
    Player player1("Joanne", 3000, 500, 200);
    player1.printStats();
    player1.addStamina(300);
    player1.printStats();

    // Code to create another player and print stats
    // Checks whether printing stats and setting stats work
    Player player2("Usagi", 1000, 4000, 700); // 4000 exceeds the limit so it should set stamina to 100
    player2.printStats();
    player2.setStrength(9000);
    player2.printStats();

    // Code to create a new board
    // Checks whether initializing and displaying the board works
    Board board1(2);
    board1.initializeBoard();
    board1.displayBoard();

    player1.Pink();
    player1.printStats();
}