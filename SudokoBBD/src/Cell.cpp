/*
 * Cell.cpp
 *
 *  Created on: 9 apr 2013
 *      Author: stekman
 */

#include "Cell.h"

Cell::Cell(int x, int y): x(x), y(y) {

}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

int Cell::GetX() const {
	return x;
}

void Cell::SetX(int x) {
	this->x = x;
}

void Cell::SetY(int y) {
	this->y = y;
}

int Cell::GetY() const {
	return y;
}
