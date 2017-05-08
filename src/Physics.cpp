#include <iostream>
#include "../include/Physics.h"

Physics::Physics()
    : m(0)
    , r(10)
    , t(0)
    , n(200)
    , maxVelocity_(250)
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
        atom.vx = (float)(rand() % (2 * maxVelocity_ + 1)) - maxVelocity_;
        atom.vy = (float)(rand() % (2 * maxVelocity_ + 1)) - maxVelocity_;
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


void Physics::update() {
    for (Atom & atom : atoms_) {
        // Обработка столкновений со стеной
        if (atom.x < r) {
            atom.vx = -atom.vx;
            atom.x = r;
        }
        else if (atom.x > windowWidth_ - r) {
            atom.vx = -atom.vx;
            atom.x = windowWidth_ - r;
        }
        if (atom.y < r) {
            atom.vy = -atom.vy;
            atom.y = r;
        }
        else if (atom.y > windowHeight_ - r) {
            atom.vy = -atom.vy;
            atom.y = windowHeight_ - r;
        }

//        std::cout << atom.x << ' ' << atom.vx << ' ' << dt.asSeconds() << '\n';
        // Увеличние скоростей
        atom.x += atom.vx * dt.asSeconds();
        atom.y += atom.vy * dt.asSeconds();
    }
}



void Physics::drawArena() {
    window_.clear();
    for (const Atom & atom : atoms_) {
        sf::CircleShape shape(r);
        shape.setOrigin(r, r);
        shape.setPosition(atom.x, atom.y);
        shape.setFillColor(sf::Color::Cyan);
        window_.setView(window_.getDefaultView());
        window_.draw(shape);
    }
    window_.display();
}



void Physics::drawPlot() {}