#pragma once
#ifndef ROCKET_H
#define ROCKET_H

#include "coordinates.h"

class Rocket {
private:
	Coordinates coordinates;
public:
	Rocket();
	void setCoordinates(Coordinates newCoordinates);
	Coordinates getCoordinates();
};

#endif