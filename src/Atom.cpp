#include "../include/Atom.h"

float getDistanceSqr(const Atom & atom1, const Atom & atom2)
{
    return (atom1.x - atom2.x) * (atom1.x - atom2.x) + (atom1.y - atom2.y) * (atom1.y - atom2.y);
}
