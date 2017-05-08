#pragma once

#include <vector>
#include "Atom.h"
#include "SFML/Graphics.hpp"

class Physics{
public:
    Physics(unsigned n, unsigned maxVelocity, float r);

    void run();

private:
    void update();
    void drawArena();
    void drawPlot();

    void buildArena();
    void processEvents();

    std::vector<Atom> atoms_;

    const sf::Time dt;
    const float r;
    const float m;
    const float t;
    const unsigned n;
    const unsigned maxVelocity_;

    const unsigned windowWidth_;
    const unsigned windowHeight_;
    sf::RenderWindow window_;
};
