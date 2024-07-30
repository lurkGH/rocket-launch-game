#pragma once
#ifndef COORDINATES_H
#define COORDINATES_h

class Coordinates {
public:
    short col;
    short row;
    Coordinates(short c = 0, short r = 0) {
        col = c;
        row = r;
    }
};

#endif