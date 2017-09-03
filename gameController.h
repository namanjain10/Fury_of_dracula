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
void decreaseScoreVampire (int* score);
void decreaseScoreHunterHospital (int* score);
void decreaseScoreDraculaTurn(int* score);
void bloodLossHunter (int* bloodPt);
void bloodLossSea (int* bloodPt);
void bloodGainCastle (int* bloodPt);
void lifeLossTrap (PlayerID x, int* health);
void lifeLossDrac (PlayerID x, int* health);
void lifeGainRest (PlayerID x,int* health);
void incrementRound (int* round);
