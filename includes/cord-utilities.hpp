#ifndef CORD_UTILITIES_HPP
#define CORD_UTILITIES_HPP

#include "cord.hpp"

Cord* ConcatCords(Cord* left_cord, Cord* right_cord);
void ReduceCords(cs128::ReferenceList<Cord*> cords);

#endif
