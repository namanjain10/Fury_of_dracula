#include "map.h"
#include "Globals.h"

struct gameData {

    GraphRep* map ;

    Trail* dracTrail;

    int score ;
    int round ;
    int* health ;
    int bloodPt ;
    LocationID* location;
    char* pastPlaysHunter;
    char* pastPlaysDrac;
};

gameData* newGameData ();

void makeMove (PlayerID player, LocationID loc, Encounter trap, gameData* data) ;
