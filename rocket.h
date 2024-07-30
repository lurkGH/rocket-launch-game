#pragma once
#ifndef ROCKET_H
#define ROCKET_H

#include "coordinates.h"

class Rocket {
private:
	int icon;
	Coordinates coordinates;
public:
	Rocket();
	Rocket(char _icon);
	void setIcon(int newIcon);
	int getIcon();
	void setCoordinates(Coordinates newCoordinates);
	Coordinates getCoordinates();
};

#endif