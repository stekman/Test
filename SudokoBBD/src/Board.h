/*
 * Board.h
 *
 *  Created on: 13 apr 2013
 *      Author: stekman
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <list>
#include <stdexcept>

class Cell;
class Region;

class Board
{
private:
	std::list<Cell*> cells;
	std::list<Region*> regions;
public:
	Board();
	Board(const Board& board);
	Board(int values[9][9]);
	virtual ~Board();
	Board& add(Region* region) throw (std::overflow_error);
	Board& add(Cell* cell) throw (std::overflow_error);
	Board& setup(int start[9][9]=nullptr);
	std::list<Region*> getRegions(int x, int y) const;
	std::list<Region*> getRegions() const;
	Cell* getCell(int x, int y) const throw (std::logic_error) ;
	bool solve();
	bool isSolved() const;
	bool isUnsolvable() const;
	bool operator==(const Board& other) const;
	explicit operator std::string() const;
};

#endif /* BOARD_H_ */
