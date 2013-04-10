/*
 * Region.cpp
 *
 *  Created on: 10 apr 2013
 *      Author: stekman
 */

#include <exception>
#include "Region.h"


Region::Region() {
	// TODO Auto-generated constructor stub

}

Region::~Region() {
	// TODO Auto-generated destructor stub
}

bool Region::isValid() const
{
	return cells.count()==9;
}

Region& Region::add(Cell* cell)
{
	if(isValid())
		throw std::overflow_error;
	if(getCell(cell->GetX(), cell->GetY())!=nullptr)
		throw std::out_of_range;
	if(cell->GetValue()!=0 && !isAvailable(cell->GetValue))
		throw std::logic_error;
	cells.push_back(cell);
	return *this;
}

Cell* Region::getCell(int x, int y) const
{
	for(auto li=cells.cbegin(); li!=cells.cend(); ++li)
	{
		if(x==li->GetX()&&y==li->GetY())
			return li;
	}
	return nullptr;
}
