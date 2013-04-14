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

using std::list;

class Region;

class Cell {
private:
	int x;
	int y;
	int value;
	std::list<Region*> regions;
public:
	Cell(int x, int y, int value = 0);
	virtual ~Cell();

	int GetX() const;
	int GetY() const;
	int GetValue() const;
	void SetValue(int value) throw (std::logic_error);
	bool isValid() const;
	void addRegion(Region* region);
	void deleteRegion(Region* region);
	int countRegions() const;
	list<int> GetFreeValues() const;
	bool isSolvable() const;
	explicit operator std::string() const;
};

#endif /* CELL_H_ */
