#pragma once
#ifndef PATH_H
#define PATH_H
#include "rocket.h"
#include <string>

using namespace std;

class Path {
private:
	int LBnd;
	int Cntr;
	int RBnd;
	Rocket rocket;
	string name;
public:
	Path();
	Path(int lbnd, int cntr, int rbnd, Rocket _rocket, string n);
	void setLBnd(int lbnd);
	void setCntr(int cntr);
	void setRBnd(int rbnd);
	void setRocket(Rocket _rocket);
	int getLBnd();
	int getCntr();
	int getRBnd();
	Rocket* getRocket();
	string getName();
};

#endif