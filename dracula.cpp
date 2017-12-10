#include "DracView.h"

LocationID DracAI (DracView view) {

    LocationID hunterLoc[NUM_PLAYERS-1];
    LocationID myLocation = whereIs (view, PLAYER_DRACULA);

    if (myLocation == NOWHERE) {
        return initDrac();
    }

    for (int i=0; i<NUM_PLAYERS-1; i++) {
        hunterLoc[i] = whereIs (view, i);
    }

    int myHealth = howHealthyIs (view, PLAYER_DRACULA);
    LocationID* edges;
    int size, virtualHealth;

    edges = whereCanIgo (view, &size, 1, 1);

    cout << "edges made "<< size << "\n";

    int hunterDistance[size], castleDistance[size];
    int maxHuntDis = 0, maxCastleDis = 0;
    double result[size];

    for (int i=0; i<size; i++) {
        result[i] = 0;
    }

    for (int i=0; i<size; i++) {
        cout << "edges are " << edges[i] << endl;
    }

    cout << "check\n";

    for (int i=0; i<size; i++) {

        hunterDistance[i] = minDist(giveMeMap(view), edges[i], hunterLoc);
        cout << "exit\n";
        if (hunterDistance[i] > maxHuntDis) {
            maxHuntDis = hunterDistance[i];
        }
    }

    for (int i=0; i<size; i++) {
        hunterDistance[i] = maxHuntDis - hunterDistance[i];
        result[i] += hunterDistance[i];
    }

    if (myHealth < 18) {

        for (int i=0; i<size; i++) {

            virtualHealth = 0 ;
            castleDistance[i] = shortestDistanceDrac (giveMeMap(view), edges[i], CASTLE_DRACULA);

            result[i] += (myHealth * castleDistance[i])/(myHealth - virtualHealth);

        }
    }

    double min = result[0];
    int pos = 0;

    for (int i=0; i<size; i++) {
        if (min > result[i]) {
            min = result[i];
            pos = i;
        }
    }
    return edges[pos];
}
