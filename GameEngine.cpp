#include <string.h>
#include <assert.h>
#include "map.h"
#include "places.h"
#include "trail.h"
#include "gameController.h"
#include "Globals.h"
#include <iostream>

using namespace std;

int main () {

    gameData* data = newGameData ();

    PlayerID currentPlayer = 0;
    int turn = 0;
    int loc = 1;

    while (turn < 200) {//gameContinue(data) ) {
        if (loc == 71) {
            loc = 0;
        }
        //cout << "gvuvhb3" << endl;
        currentPlayer = turn%5 ;

        if (currentPlayer == PLAYER_DRACULA) {
            // DracView view = newDracView (pastplaysDrac);
            // char* result = DracAI (view);
            makeMove (currentPlayer, loc, TRAP, data);
            cout << "dracula" << endl;
            //cout << data->pastPlaysHunter << endl;//strlen(data->pastPlaysHunter)<< endl ;
            //cout << data->pastPlaysDrac << endl;//strlen(data->pastPlaysDrac) << endl ;
        }

        else {
            // HunterView view = newHunterView (pastPlaysHunter);
            // char* result = HunterAI (view);
            makeMove (currentPlayer, loc, NO_ENCOUNTER, data);
            cout << "hunter" << endl;
            //cout << data->pastPlaysHunter << endl;//strlen(data->pastPlaysHunter)<< endl ;
            //cout << data->pastPlaysDrac << endl;//strlen(data->pastPlaysDrac) << endl ;
        }

        //evaluate (result,currentPlayer);
        loc ++;
        turn ++;
    }

    cout << data->pastPlaysHunter << endl ;
    cout << data->pastPlaysDrac << endl ;
}
