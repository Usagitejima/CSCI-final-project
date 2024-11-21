//Donna and Joanne

#include "Board.h"
#include "Player.h"
#include "Tile.h"

int main(){
    Player player1("Joanne", 3000, 500, 200);
    player1.printStats();
    player1.addStamina(300);
    player1.printStats();

    Player player2("Usagi", 1000, 4000, 700);  // 4000 exceeds the limit so it should set stamina to 100
    player2.printStats();
    player2.setStrength(9000); 
    player2.printStats();

    Board board1(2);
    board1.initializeBoard();
    board1.displayBoard();

    

}