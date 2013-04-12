/*
 * Cell_test.cpp
 *
 *  Created on: 9 apr 2013
 *      Author: stekman
 */

#include "Cell.h"
#include "Region.h"
#include "igloo/igloo_alt.h"

using namespace igloo;

Describe(A_Cell)
{
	It(HasCoordinates)
	{
		Cell cell(1,9);
		Assert::That(cell.GetX(), Equals(2));
		Assert::That(cell.GetY(), Equals(9));
	}

	It(HasAValue)
	{
		Cell cell(1,9);
		Assert::That(cell.GetValue(), Equals(0));

		cell.SetValue(5);
		Assert::That(cell.GetValue(), Equals(5));
	}

	It(IsValidInRegion)
	{
		Cell cell(1,9);
		Region region;

	}

	It(IsInvalid)
	{
		Cell cell(1,9);

	}
};

