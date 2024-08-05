#include "rocket.h"
#include <string>
#include <vector>
using namespace std;

// Constructors:

Rocket::Rocket() {
	coordinates = Coordinates();
	icon = { " ^",
			 "/|\\",
			 "/ \\" };
}

// Setters:

void Rocket::setCoordinates(Coordinates newCoordinates) {
	coordinates = newCoordinates;
}

// Getters:

Coordinates Rocket::getCoordinates() {
	return coordinates;
}

vector<string> Rocket::getIcon() {
	return icon;
}
