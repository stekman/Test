/*
 * Region.h
 *
 *  Created on: 10 apr 2013
 *      Author: stekman
 */

#ifndef REGION_H_
#define REGION_H_

#include "Cell.h"
#include <list>
#include <exception>

class Region {
private:
	std::list<shared_ptr<Cell> > cells;
public:
	Region();
	virtual ~Region();
	bool isValid() const;
	Region& add(Cell* cell) throw (std::logic_error, std::out_of_range, std::overflow_error);
	Cell* getCell(int x, int y) const;
};

#endif /* REGION_H_ */
