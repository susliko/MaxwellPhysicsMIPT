#pragma once

#include <cmath>

struct Atom{
    float x;
    float y;
    float vx;
    float vy;
};

float getDistance(const Atom & atom1, const Atom & atom2);