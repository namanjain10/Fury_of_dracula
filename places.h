#include <string.h>
#include <iostream>
using namespace std;

struct Place {
   string name;
   string abbrev;
   LocationID id;
   PlaceType type;
} ;

Place* getPlaces () ;
