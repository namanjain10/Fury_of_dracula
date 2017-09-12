#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "map.h"
#include "Globals.h"
//#include "queue.h"

#include <iostream>

using namespace std;

struct gameData {

    GraphRep* map ;

    Queue* dracTrail;

    int score ;
    int round ;
    int health [NUM_PLAYERS] ;
    LocationID location [NUM_PLAYERS];
    string pastPlaysHunter;
    string pastPlaysDrac;
    int hide[NUM_PLAYERS] ;
};

gameData* newGameData ();

void makeMove (PlayerID player, LocationID loc, gameData* data) ;
bool checkRail (LocationID from, LocationID to, int u, GraphRep* map);
bool gameContinue (gameData* data);
bool isValid (gameData* data, LocationID to, PlayerID player);
string revealDracPos (string a, Queue* b, PlayerID player, int n) ;

# endif
