
struct gameData {

    GraphRep* map ;

    Trail* dracTrail;

    int score ;
    int round ;
    int* health ;
    int bloodPt ;
    LocationID* location;
    char* pastPlaysHunter;
    char* pastplaysDrac;
}

gameData* newGameData () {

    gameData* a = new gameData;
    a->map = newGraph(71);
    constMap(a->map);

    a->round = 0;
    a->score = GAME_START_SCORE;
    a->bloodPt = GAME_START_BLOOD_POINTS;

    a->health = init_health ();
    a->location = init_location();

    a->dracTrail = newTrail();

    for (int j = 0; j<6; j++) {
        pushToTrail(a->dracTrail, UNKNOWN_LOCATION);
    }
    a->pastPlaysHunter = "";
    a->pastplaysDrac = "";

    return a;
}

int makeMove (PlayerID player, LocationID loc, gameData* data) {

    if (isValid (data->location[player], loc, data->map)) {  // to be made return boolean if move is valid
        data->location[player] = loc;

        if (player != PLAYER_DRACULA) {

            q = inTrail (data->dracTrail, loc);

            if (q == -1) {

                char fir = getFirstLetter (player);
                char r[] = getAbbrev (loc);

                char* s = new char[8];
                s[0] = fir;
                strcat (s,r);
                strcat (s,".... ");

                char* h = new char[strlen(data->pastPlaysHunter) + 8];
                strcat (h,s);

                char* t = new char[strlen(data->pastPlaysDrac) + 8];
                strcat (t,s);

            }

            else {
                // addTrap and change hunternpastPlay
            }
        }

        else {

        }
    }

    else {
        return -1;
    }
}

bool isValid (PlayerID)
