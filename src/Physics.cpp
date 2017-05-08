#include <iostream>
#include "../include/Physics.h"

Physics::Physics()
    : m(0)
    , r(10)
    , t(0)
    , n(50)
    , maxVelocity_(100)
    , windowWidth_(1366 / 2)
    , windowHeight_(700)
    , window_(sf::VideoMode(windowWidth_, windowHeight_), "Maxwell")
    , dt(sf::seconds(1.f/60.f)){}



void Physics::run() {
    buildArena();

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window_.isOpen()) {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > dt) {
            timeSinceLastUpdate -= dt;
            processEvents();
            update();
        }
        drawArena();
        drawPlot();
    }
}



void Physics::buildArena() {
    srand(256);
    for (unsigned i = 0; i < n; i++) {
        Atom atom;
        atom.x = rand() % windowWidth_;
        atom.y = rand() % windowHeight_;
        atom.vx = rand() % maxVelocity_;
        atom.vy = rand() % maxVelocity_;
//        std::cout << atom.x << "; " << atom.y << " / " << atom.vx << "; " << atom.vy << "\n";
        atoms_.push_back(std::move(atom));
    }
}



void Physics::processEvents() {
    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window_.close();
        }
    }
}


void Physics::update() {}



void Physics::drawArena() {
    window_.clear();
    for (const Atom & atom : atoms_) {
        sf::CircleShape rect(r);
        rect.setPosition(atom.x, atom.y);
        rect.setFillColor(sf::Color::Cyan);
        window_.setView(window_.getDefaultView());
        window_.draw(rect);
    }
    window_.display();
}



void Physics::drawPlot() {}