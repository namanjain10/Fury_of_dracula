//int* init_score ();
//int* init_round ();
int* init_health ();
//int* init_bloodPt ();
PlayerID* init_location ();
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


void registerBestPlay( char *play, PlayerMessage message );
