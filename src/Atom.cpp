#include "../include/Atom.h"

float getDistance(const Atom & atom1, const Atom & atom2)
{
    return sqrtf((atom1.x - atom2.x) * (atom1.x - atom2.x) + (atom1.y - atom2.y) * (atom1.y - atom2.y));
}
