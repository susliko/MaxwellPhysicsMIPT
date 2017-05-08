#include "../include/Utility.h"

float lenghtSqr(const sf::Vector2f & v)
{
    return v.x * v.x + v.y * v.y;
}



float dotProduct(const sf::Vector2f & L, const sf::Vector2f & R)
{
    return L.x * R.x + L.y * R.y;
}



sf::Vector2f projection(const sf::Vector2f & base, const sf::Vector2f & other)
{
    return dotProduct(base, other) * base / lenghtSqr(base);
}