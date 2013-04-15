/*
 * Cell.h
 *
 *  Created on: 9 apr 2013
 *      Author: stekman
 */

#ifndef CELL_H_
#define CELL_H_
#include <list>
#include <stdexcept>
#include <string>

#include "DataHandler.h"

using std::list;

class Region;

class Cell : public DataHandler
{
private:
	int x;
	int y;
	int value;
	std::list<Region*> regions;
	mutable list<int> free;
public:
	Cell(int x, int y, int value = 0);
	virtual ~Cell();
	int getX() const;
	int getY() const;
	int getValue() const;
	void setValue(int value) throw (std::logic_error);
	void addRegion(Region* region);
	void deleteRegion(Region* region);
	int countRegions() const;
	list<int> getFreeValues() const;
	bool isSolvable() const;
	explicit operator std::string() const;
	void doMakeValid() const;
};

#endif /* CELL_H_ */
