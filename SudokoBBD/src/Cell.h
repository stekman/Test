/*
 * Cell.h
 *
 *  Created on: 9 apr 2013
 *      Author: stekman
 */

#ifndef CELL_H_
#define CELL_H_

class Cell {
private:
	int x;
	int y;
	int value;
public:
	Cell(int x, int y);
	virtual ~Cell();
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);
	int GetValue() const;
	void SetValue(int value);
};

#endif /* CELL_H_ */