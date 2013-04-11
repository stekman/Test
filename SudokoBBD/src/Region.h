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
#include <memory>

class Region {
private:
    std::list<std::shared_ptr<Cell> > cells;
public:
    Region();
    virtual ~Region();
    bool isValid() const;
    Region& add(Cell* cell) throw (std::logic_error, std::out_of_range, std::overflow_error);
    Cell* getCell(int x, int y) const;
    bool hasValue(int i) const;
    std::list<int> getValues() const;
    std::list<int> getFreeValues() const;
};

#endif /* REGION_H_ */
