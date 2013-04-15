/*
 * Board.cpp
 *
 *  Created on: 13 apr 2013
 *      Author: stekman
 */

#include "Board.h"
#include "Region.h"
#include <iostream>
#include <sstream>

Board::Board()
{
}

Board::Board(int values[9][9])
{
	setup(values);
}

Board::~Board()
{
	for(auto region: regions)
	{
		delete region;
	}
}

Board& Board::add(Region* region) throw (std::overflow_error)
{
	if(regions.size()>=3*9)
		throw std::overflow_error("Too many regions");
	regions.push_back(region);
	return *this;
}

Board& Board::add(Cell* cell) throw (std::overflow_error)
{
	if(cells.size()>=9*9)
		throw std::overflow_error("Too many cells");
	cells.push_back(cell);
	auto regionsForCell=getRegions(cell->getX() ,cell->getY());
	for(auto region: regionsForCell)
		region->add(cell);
	return *this;
}

Board& Board::setup(int start[9][9])
{
	for(int type=0; type<(int)Region::undefined; ++type)
		for(int position=1; position<=9; position++)
			add(new Region((Region::Type)type,position));
	for(int x=1; x<=9; x++)
		for(int y=1; y<=9; y++)
			add(new Cell(x,y,start!=nullptr?start[x-1][y-1]:0));
	return *this;
}

std::list<Region*> Board::getRegions(int x, int y) const
{
	std::list<Region*> selection;
	for(auto region : regions)
	{
		if(region->getType()==Region::horizontal and region->getPosition()==x)
			selection.push_back(region);
		if(region->getType()==Region::vertical and region->getPosition()==y)
			selection.push_back(region);
	}
	for(auto region: regions)
		if(region->getType()==Region::area and region->getPosition()==(x-1)/3+((y-1)/3)*3+1)
		{
			selection.push_back(region);
			break;
		}
	return selection;
}

std::list<Region*> Board::getRegions() const
{
	return regions;
}

Cell* Board::getCell(int x, int y) const throw (std::logic_error)
{
	for(auto cell: cells)
	{
		if(cell->getX()==x and cell->getY()==y)
			return cell;
	}
	throw std::logic_error("Invalid cell");
}

Board::Board(const Board& board)
{
	setup();
	for(auto cell : board.cells)
	{
		getCell(cell->getX(),cell->getY())->setValue(cell->getValue());
	}
}

bool Board::solve()
{
	for(;;)
	{
		if(isSolved())
			return true;
		if(isUnsolvable())
			return false;
		bool changed;
		changed=true;
		while(changed)
		{
			changed=false;
			for(auto cell : cells)
			{
				if(cell->getValue()==0)
				{
					auto possible = cell->getFreeValues();
					if(possible.size()==1)
					{
						cell->setValue(*possible.begin());
						changed = true;
					}
				}
			}
		}
		if(isSolved())
			return true;
		Cell* best=nullptr;
		unsigned int bestpossible=10;
		for(Cell* cell : cells)
		{
			if(cell->getValue()==0 and cell->getFreeValues().size()<bestpossible)
			{
				best=cell;
				bestpossible=cell->getFreeValues().size();
			}
		}
		for(int value: best->getFreeValues())
		{
			Board subBoard(*this);
			subBoard.getCell(best->getX(),best->getY())->setValue(value);
			if(subBoard.solve())
			{
				getCell(best->getX(),best->getY())->setValue(value);
				changed=true;
				break;
			}
		}
		if(!changed)
			return false;
	}
	return false;
}

bool Board::isSolved() const
{
	for(int x=1;x<=9;x++)
		for(int y=1;y<=9; y++)
			if(getCell(x,y)->getValue()==0)
				return false;
	return true;
}

bool Board::operator ==(const Board& other) const
{
	bool result = true;
	if(cells.size()==other.cells.size())
		for(auto firstBoardCell=cells.cbegin(), otherBoardCell=other.cells.cbegin();
			firstBoardCell!=cells.cend()&&otherBoardCell!=other.cells.cend();
			firstBoardCell++, otherBoardCell++)
		{
			if((*firstBoardCell)->getValue()!=(*otherBoardCell)->getValue())
			{
				result = false;
				break;
			}
		}
		else
			result = false;
	return result;
}

bool Board::isUnsolvable() const
{
	for(auto cell: cells)
		if(cell->getValue()==0 and not cell->isSolvable())
			return true;
	return false;
}

Board::operator std::string() const
{
	std::stringstream result;
	result << "{";
	for(int x=1; x<=9;x++)
	{
		result << "{" << getCell(x,1)->getValue();
		for(int y=2; y<=9;y++)
			result << "," << getCell(x,y)->getValue();
		result << "}" << std::endl;
	}
	result << "}" << std::endl;
	return result.str();
}
