#pragma once

#include <vector>
#include "Atom.h"
#include "SFML/Graphics.hpp"

class Physics{
public:
    Physics();

    void run();

private:
    void update();
    void drawArena();
    void drawPlot();

    std::vector<Atom> atoms_;

    const double r;
    const double m;
    const double t;
    const int n;
};
