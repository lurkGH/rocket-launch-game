#include "rocket.h"

// Constructors:

Rocket::Rocket() {
	icon = 0;
	coordinates = Coordinates();
}

Rocket::Rocket(char _icon) {
	icon = static_cast<int>(_icon);
	coordinates = Coordinates();
}

// Setters:

void Rocket::setIcon(int newIcon) {
	icon = newIcon;
}

void Rocket::setCoordinates(Coordinates newCoordinates) {
	coordinates = newCoordinates;
}

// Getters:

int Rocket::getIcon() {
	return icon;
}

Coordinates Rocket::getCoordinates() {
	return coordinates;
}
