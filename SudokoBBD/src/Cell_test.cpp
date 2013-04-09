/*
 * Cell_test.cpp
 *
 *  Created on: 9 apr 2013
 *      Author: stekman
 */

#include "Cell.h"
#include "igloo/igloo_alt.h"
using namespace igloo;

Describe(A_Cell)
{
	It(HasCoordinates)
	{
		Cell cell(10,20);
		Assert::That(cell.GetX(), Equals(10));
		Assert::That(cell.GetY(), Equals(20));
	}
};
