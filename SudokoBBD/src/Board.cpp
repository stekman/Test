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
	// TODO Auto-generated constructor stub

}

Board::~Board()
{
	// TODO Auto-generated destructor stub
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
	auto regionsForCell=GetRegions(cell->GetX() ,cell->GetY());
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

std::list<Region*> Board::GetRegions(int x, int y) const
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

std::list<Region*> Board::GetRegions() const
{
	return regions;
}

Cell* Board::GetCell(int x, int y) const throw (std::logic_error)
{
	for(auto cell: cells)
	{
		if(cell->GetX()==x and cell->GetY()==y)
			return cell;
	}
	throw std::logic_error("Invalid cell");
}

Board::Board(const Board& board)
{
	setup();
	for(auto cell : board.cells)
	{
		GetCell(cell->GetX(),cell->GetY())->SetValue(cell->GetValue());
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
				if(cell->GetValue()==0)
				{
					auto possible = cell->GetFreeValues();
					if(possible.size()==1)
					{
						cell->SetValue(*possible.begin());
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
			if(cell->GetValue()==0 and cell->GetFreeValues().size()<bestpossible)
			{
				best=cell;
				bestpossible=cell->GetFreeValues().size();
			}
		}
		for(int value: best->GetFreeValues())
		{
			Board subBoard(*this);
			subBoard.GetCell(best->GetX(),best->GetY())->SetValue(value);
			if(subBoard.solve())
			{
				GetCell(best->GetX(),best->GetY())->SetValue(value);
				changed=true;
				break;
			}
		}
		if(!changed)
			return false;
	}
}

bool Board::isSolved() const
{
	for(int x=1;x<=9;x++)
		for(int y=1;y<=9; y++)
			if(GetCell(x,y)->GetValue()==0)
				return false;
	return true;
}

bool Board::operator ==(const Board other) const
{
	bool result = true;
	if(cells.size()==other.cells.size())
		for(auto firstBoardCell=cells.cbegin(), otherBoardCell=other.cells.cbegin();
			firstBoardCell!=cells.cend()&&otherBoardCell!=other.cells.cend();
			firstBoardCell++, otherBoardCell++)
		{
			if((*firstBoardCell)->GetValue()!=(*otherBoardCell)->GetValue())
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
		if(cell->GetValue()==0 and not cell->isSolvable())
			return true;
	return false;
}

Board::operator std::string() const
{
	std::stringstream result;
	result << "{";
	for(int x=1; x<=9;x++)
	{
		result << "{" << GetCell(x,1)->GetValue();
		for(int y=2; y<=9;y++)
			result << "," << GetCell(x,y)->GetValue();
		result << "}" << std::endl;
	}
	result << "}" << std::endl;
	return result.str();
}
