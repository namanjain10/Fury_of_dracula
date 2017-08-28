#include "trail.h"
#include "places.h"
#include "Globals.h"
#include "gameData.h"

int* init_health () {
    int* health = new int[NUM_PLAYERS-1]{GAME_START_HUNTER_LIFE_POINTS, GAME_START_HUNTER_LIFE_POINTS, GAME_START_HUNTER_LIFE_POINTS, GAME_START_HUNTER_LIFE_POINTS}
    return health;
}

PlayerID* init_location () {
    PlayerID* a = new PlayerID[NUM_PLAYERS]{NOWHERE, NOWHERE, NOWHERE, NOWHERE, NOWHERE};
    return a;
}

void decreaseScoreVampire (int* score) {
    *score = *score - SCORE_LOSS_VAMPIRE_MATURES;
}

void decreaseScoreHunterHospital (int* score) {
    *score = *score - SCORE_LOSS_HUNTER_HOSPITAL;
}

void decreaseScoreDraculaTurn(int* score) {
    *score = *score - SCORE_LOSS_DRACULA_TURN;
}

void bloodLossHunter (int* bloodPt) {
    *bloodPt = *bloodPt - LIFE_LOSS_HUNTER_ENCOUNTER;
}

void bloodLossSea (int* bloodPt) {
    *bloodPt = *bloodPt - LIFE_LOSS_SEA;
}

void bloodGainCastle (int* bloodPt) {
    *bloodPt = *bloodPt + LIFE_GAIN_CASTLE_DRACULA;
}

void lifeLossTrap (PlayerID x, int* health) {
    health[x] = health[x] - LIFE_LOSS_TRAP_ENCOUNTER;
}

void lifeLossDrac (PlayerID x, int* health) {
    health[x] = health[x] - LIFE_LOSS_DRACULA_ENCOUNTER;
}

void lifeGainRest (PlayerID x,int* health) {
    health[x] = health[x] + LIFE_GAIN_REST;
}

void incrementRound (int* round) {
    *round = *round + 1;
}
