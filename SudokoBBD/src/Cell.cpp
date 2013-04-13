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

Cell::Cell(int x, int y, int value): x(x), y(y)
{
	SetValue(value);
}

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

int Cell::GetX() const {
	return x;
}

int Cell::GetValue() const {
	return value;
}

void Cell::SetValue(int value) throw (std::logic_error)
{
	for(auto region: regions)
		if(region->hasValue(value))
			throw std::logic_error("A cell in the region already has value");
	this->value = value;
}

int Cell::GetY() const {
	return y;
}

bool Cell::isValid() const
{
	return regions.size()==3;
}

void Cell::addRegion(Region* region)
{
	if(countRegions()>2)
		throw std::out_of_range("Maximum three regions");
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
}

int Cell::countRegions() const
{
	return regions.size();
}

list<int> Cell::GetFreeValues() const
{
	list<int> free;
	auto region = regions.cbegin();
	if(region!=regions.cend())
		free = (*region)->GetFreeValues();
	region++;
	for(; region != regions.cend(); region++)
	{
		list<int> freeInRegion = (*region)->GetFreeValues();
		list<int> totalFree;
		std::set_intersection(free.cbegin(), free.cend(), freeInRegion.cbegin(), freeInRegion.cend(), std::back_inserter(totalFree));
		free = totalFree;
	}
	return free;
}

bool Cell::isSolvable() const
{
	return GetFreeValues().size()!=0;
}
