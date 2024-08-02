#include "rocket.h"

// Constructors:

Rocket::Rocket() {
	coordinates = Coordinates();
}

// Setters:

void Rocket::setCoordinates(Coordinates newCoordinates) {
	coordinates = newCoordinates;
}

// Getters:

Coordinates Rocket::getCoordinates() {
	return coordinates;
}
