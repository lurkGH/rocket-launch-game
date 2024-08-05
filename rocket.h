#pragma once
#ifndef ROCKET_H
#define ROCKET_H

#include "coordinates.h"
#include <string>
#include <vector>
using namespace std;

class Rocket {
private:
	Coordinates coordinates;
	vector<string> icon;
public:
	Rocket();
	void setCoordinates(Coordinates newCoordinates);
	Coordinates getCoordinates();
	vector<string> getIcon();
};

#endif