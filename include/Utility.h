#pragma once

#include "SFML/Graphics.hpp"

float lenghtSqr(const sf::Vector2f & v);

float dotProduct(const sf::Vector2f & L, const sf::Vector2f & R);

sf::Vector2f projection(const sf::Vector2f & base, const sf::Vector2f & other);