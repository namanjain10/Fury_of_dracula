#include "gameData.h"

data = newGameData ();

PlayerID currentPlayer = 0;
int turn = 0;

while ( gameContinue(data) ) {

    currentPlayer = turn%5 ;

    if (currentPlayer == PLAYER_DRACULA) {
        DracView view = newDracView (pastplaysDrac);
        char* result = DracAI (view);
    }

    else {
        HunterView view = newHunterView (pastPlaysHunter);
        char* result = HunterAI (view);
    }

    evaluate (result,currentPlayer);
    currentPlayer ++;
}
