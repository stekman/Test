/*
 * Region.cpp
 *
 *  Created on: 10 apr 2013
 *      Author: stekman
 */

#include <exception>
#include <list>
#include <string>
#include "Region.h"


Region::Region(Type type, int position) : type(type), position(position)
{}

Region::~Region() {
    for(auto cell: cells)
    {
    	cell->deleteRegion(this);
    	if(cell->countRegions()==0)
    		delete cell;
    }
}

bool Region::isValid() const
{
    return cells.size()==9;
}

Region& Region::add(Cell* cell) throw (std::logic_error, std::out_of_range, std::overflow_error)
{
    if(isValid())
        throw std::overflow_error("Region is already full: "+std::string(*cell));
    try
    {
    	getCell(cell->getX(), cell->getY());
        throw std::out_of_range("A cell already has this position: "+std::string(*cell));
    }
    catch (std::logic_error& e)
    { }
    if(cell->getValue()!=0 && hasValue(cell->getValue()))
    {
    	throw std::logic_error("A cell already has this value in the region: "+std::string(*cell));
    }
    cell->addRegion(this);;
    cells.push_back(cell);
    return *this;
}

Cell* Region::getCell(int x, int y) const
{
    for(auto cell:cells)
    {
        if(x==cell->getX()&&y==cell->getY())
            return cell;
    }
    throw std::logic_error("Cell does not exist");
}

std::list<int> Region::getValues() const
{
    std::list<int> values;
    for(auto cell :cells)
    {
        if(cell->getValue()!=0)
            values.push_back(cell->getValue());
    }
    values.sort();
    return values;
}

int Region::getPosition() const
{
	return position;
}

Region::Type Region::getType() const
{
	return type;
}

std::list<int> Region::getFreeValues() const
{
    std::list<int> free;
    for(int value=1; value<=9; value++)
    {
        if(!hasValue(value))
        {
            free.push_back(value);
        }
    }
    free.sort();
    return free;
}

bool Region::hasValue( int i ) const
{
    for(auto cell : cells)
    {
        if(cell->getValue() == i)
            return true;
    }
    return false;
}
