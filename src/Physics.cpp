#include <iostream>
#include "../include/Physics.h"
#include "../include/Utility.h"

Physics::Physics(unsigned n, unsigned maxVelocity, float r)
    : m(0)
    , r(r)
    , t(0)
    , n(n)
    , maxVelocity_(maxVelocity)
    , windowWidth_(650)
    , windowHeight_(700)
    , window_(sf::VideoMode(windowWidth_, windowHeight_), "Maxwell")
    , dt(sf::seconds(1.f / 60.f))
    , drawer_(600, 600, "Maxwell", maxVelocity_, n, 20)
{}



void Physics::run()
{
    buildArena();

    sf::Clock clock;
    sf::Clock clock2;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time sinceLastDraw = sf::Time::Zero;
    while (window_.isOpen()) {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > dt) {
            timeSinceLastUpdate -= dt;
            processEvents();
            update();
        }
        drawArena();
        if (clock2.getElapsedTime() > sf::seconds(0.15)) {
            drawPlot();
            clock2.restart();
        }
    }
}



void Physics::buildArena()
{
    srand(256);
    for (unsigned i = 0; i < n; i++) {
        Atom atom;
        atom.x = rand() % windowWidth_;
        atom.y = rand() % windowHeight_;
        atom.vx = maxVelocity_ / 2;//(float)(rand() % (2 * maxVelocity_ + 1)) - maxVelocity_;
        atom.vy = maxVelocity_ / 2;//(float)(rand() % (2 * maxVelocity_ + 1)) - maxVelocity_;
        atoms_.push_back(std::move(atom));
    }
}



void Physics::processEvents()
{
    sf::Event event;
    while (window_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window_.close();
        }
    }
}


void Physics::update()
{
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

        // Увеличние скоростей
        atom.x += atom.vx * dt.asSeconds();
        atom.y += atom.vy * dt.asSeconds();
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            Atom & atom1 = atoms_[i];
            Atom & atom2 = atoms_[j];
            if (getDistanceSqr(atom1, atom2) < 4 * r * r) {
                Atom tmp = atom1;
                atom1 = atom2;
                atom2 = tmp;

                sf::Vector2f delta(atom1.x - atom2.x, atom1.y - atom2.y);
                sf::Vector2f v1(atom1.vx, atom1.vy);
                sf::Vector2f v2(atom2.vx, atom2.vy);

                sf::Vector2f v1n = projection(-delta, v1);
                sf::Vector2f v2n = projection(delta, v2);

                v1 = v1 - v1n + v2n;
                v2 = v2 - v2n + v1n;

                atom1.vx = v1.x;
                atom1.vy = v1.y;
                atom2.vx = v2.x;
                atom2.vy = v2.y;

                atom1.x = atom2.x + delta.x * 2 * r / sqrtf(lenghtSqr(delta));
                atom1.y = atom2.y + delta.y * 2 * r / sqrtf(lenghtSqr(delta));
            }
        }
}



void Physics::drawArena()
{
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



void Physics::drawPlot()
{
    std::vector<double> velocities;
    for (Atom a : atoms_) {
        velocities.push_back(sqrt(a.vx * a.vx + a.vy * a.vy));
    }
    drawer_.draw(velocities);
}