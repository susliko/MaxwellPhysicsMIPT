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

    void buildArena();
    void processEvents();

    std::vector<Atom> atoms_;

    const sf::Time dt;
    const double r;
    const double m;
    const double t;
    const unsigned n;

    const unsigned windowWidth_;
    const unsigned windowHeight_;
    sf::Window window_;
};
