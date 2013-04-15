/*
 * Cell.cpp
 *
 *  Created on: 9 apr 2013
 *      Author: stekman
 */

#include "Cell.h"
#include "Region.h"
#include <algorithm>
#include <iostream>
#include <sstream>

Cell::Cell(int x, int y, int value): x(x), y(y)
{
	setValue(value);
}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

int Cell::getX() const {
	return x;
}

int Cell::getValue() const {
	return value;
}

void Cell::setValue(int value) throw (std::logic_error)
{
	if(value!=0)
		for(auto region: regions)
			if(region->hasValue(value))
				throw std::logic_error("A cell in the region already has value");

	if(value!=this->value)
	{
		this->value = value;
		onChange();
	}
}

int Cell::getY() const {
	return y;
}


void Cell::addRegion(Region* region)
{
	if(countRegions()>2)
		throw std::out_of_range("Maximum three regions");
	onChange();
	subscribe(region);
	regions.push_back(region);
}

void Cell::deleteRegion(Region* region)
{
	for(auto search=regions.begin(); search!=regions.end();search++)
		if(*search==region)
		{
			regions.erase(search);
			return;
		}
	onChange();
}

int Cell::countRegions() const
{
	return regions.size();
}

list<int> Cell::getFreeValues() const
{
	if(getState()==DataHandler::VALID)
		return free;
	else
	{
		makeValid();
		return free;
	}
}


bool Cell::isSolvable() const
{
	return getFreeValues().size()!=0;
}

Cell::operator std::string() const
{
	std::stringstream result;
	result << "Cell (" << x << ", " << y << ") = " << value;
	return result.str();
}

void Cell::doMakeValid() const
{
	free.clear();
	auto region = regions.cbegin();
	if(region!=regions.cend())
		free = (*region)->getFreeValues();
	region++;
	for(; region != regions.cend(); region++)
	{
		list<int> freeInRegion = (*region)->getFreeValues();
		list<int> totalFree;
		std::set_intersection(free.cbegin(), free.cend(), freeInRegion.cbegin(), freeInRegion.cend(), std::back_inserter(totalFree));
		free = totalFree;
	}
}
