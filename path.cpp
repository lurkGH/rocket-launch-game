#include "path.h"
#include <string>

// Constructors:

Path::Path() {
	LBnd = 0;
	Cntr = 0;
	RBnd = 0;
	rocket = Rocket();
	name = "";
}

Path::Path(int lbnd, int cntr, int rbnd, Rocket _rocket, string n) {
	LBnd = lbnd;
	Cntr = cntr;
	RBnd = rbnd;
	rocket = _rocket;
	name = n;
}

// Setters:

void Path::setLBnd(int lbnd) {
	LBnd = lbnd;
}

void Path::setCntr(int cntr) {
	Cntr = cntr;
}

void Path::setRBnd(int rbnd) {
	RBnd = rbnd;
}

void Path::setRocket(Rocket _rocket) {
	rocket = _rocket;
}

// Getters:

int Path::getLBnd() {
	return LBnd;
}

int Path::getCntr() {
	return Cntr;
}

int Path::getRBnd() {
	return RBnd;
}

Rocket* Path::getRocket() {
	return &rocket;
}

string Path::getName() {
	return name;
}
