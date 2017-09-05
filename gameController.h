#include "map.h"
#include "Globals.h"
#include "trail.h"

#include <iostream>

using namespace std;

struct gameData {

    GraphRep* map ;

    Trail* dracTrail;

    int score ;
    int round ;
    int health [NUM_PLAYERS-1] ;
    int bloodPt ;
    LocationID location [NUM_PLAYERS-1];
    string pastPlaysHunter;
    string pastPlaysDrac;
    int hide[NUM_PLAYERS] ;
};

gameData* newGameData ();

void makeMove (PlayerID player, LocationID loc, Encounter trap, gameData* data) ;
bool checkRail (LocationID from, LocationID to, int u, GraphRep* map);

bool isValid (gameData* data, LocationID to, PlayerID player);
