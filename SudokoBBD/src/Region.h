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
#include <stdexcept>
#include <memory>
#include "DataHandler.h"

class Cell;

class Region : public DataHandler
{
public:
	typedef enum {horizontal, vertical, area, undefined } Type;
private:
    std::list<Cell*> cells;
    Type type;
    int position;
    mutable std::list<int> free;
public:
    Region(Type type=undefined, int pos=0);
    virtual ~Region();
    bool isValid() const;
    Region& add(Cell* cell) throw (std::logic_error, std::out_of_range, std::overflow_error);
    Cell* getCell(int x, int y) const;
    bool isCell(int x, int y) const;
    bool hasValue(int i) const;
    std::list<int> getValues() const;
    std::list<int> getFreeValues() const;
	int getPosition() const;
	Type getType() const;
	void doMakeValid() const;
};

#endif /* REGION_H_ */
