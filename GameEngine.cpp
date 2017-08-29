#include <string.h>
#include "map.h"
#include "places.h"
#include "trail.h"
#include "gameController.h"
#include "Globals.h"
#include <iostream>

using namespace std;

int main () {

cout << "gvuvhb" << endl;
gameData* data = newGameData ();
cout << "gvuvhb" << endl;

PlayerID currentPlayer = 0;
int turn = 0;
int loc = 1;

cout << "gvuvhb" << endl;

while (turn < 16) {//gameContinue(data) ) {
    cout << "gvuvhb" << endl;
    currentPlayer = turn%5 ;

    if (currentPlayer == PLAYER_DRACULA) {
        // DracView view = newDracView (pastplaysDrac);
        // char* result = DracAI (view);
        makeMove (currentPlayer, TRAP, loc, data);
        cout << "gvuvhb" << endl;
    }

    else {
        // HunterView view = newHunterView (pastPlaysHunter);
        // char* result = HunterAI (view);
        makeMove (currentPlayer, NO_ENCOUNTER, loc, data);
        cout << "gvuvhb" << endl;
    }

    //evaluate (result,currentPlayer);
    loc ++;
    turn ++;
}

cout << data->pastPlaysHunter << endl ;
cout << data->pastPlaysDrac << endl ;
}
