#pragma once

#include <cmath>

struct Atom{
    float x;
    float y;
    float vx;
    float vy;
};

float getDistanceSqr(const Atom & atom1, const Atom & atom2);