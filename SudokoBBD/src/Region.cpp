/*
 * Region.cpp
 *
 *  Created on: 10 apr 2013
 *      Author: stekman
 */

#include <exception>
#include <list>
#include "Region.h"


Region::Region() {
    // TODO Auto-generated constructor stub

}

Region::~Region() {
    // TODO Auto-generated destructor stub
}

bool Region::isValid() const
{
    return cells.size()==9;
}

Region& Region::add(Cell* cell) throw (std::logic_error, std::out_of_range, std::overflow_error)
{
    if(isValid())
        throw std::overflow_error("Region is already full");
    if(getCell(cell->GetX(), cell->GetY())!=nullptr)
        throw std::out_of_range("A cell already has this position");
    if(cell->GetValue()!=0 && hasValue(cell->GetValue()))
        throw std::logic_error("A cell already has this value in the region");
    std::shared_ptr<Cell> shared(cell);
    cells.push_back(shared);
    return *this;
}

Cell* Region::getCell(int x, int y) const
{
    for(auto li=cells.cbegin(); li!=cells.cend(); ++li)
    {
        if(x==(*li)->GetX()&&y==(*li)->GetY())
            return li->get();
    }
    return nullptr;
}

std::list<int> Region::getValues() const
{
    std::list<int> values;
    for(auto cell = cells.cbegin(); cell!=cells.cend(); cell++)
    {
        if((*cell)->GetValue()!=0)
            values.push_back((*cell)->GetValue());
    }
    values.sort();
    return values;
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
    return free;
}

bool Region::hasValue( int i ) const
{
    for(auto cell = cells.cbegin(); cell!=cells.cend(); cell++)
    {
        if((*cell)->GetValue() == i)
            return true;
    }
    return false;
}
