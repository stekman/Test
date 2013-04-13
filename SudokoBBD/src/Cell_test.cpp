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
		Assert::That(cell.GetX(), Equals(1));
		Assert::That(cell.GetY(), Equals(9));
	}

	It(HasAValue)
	{
		Cell cell(1,9);
		Assert::That(cell.GetValue(), Equals(0));

		cell.SetValue(5);
		Assert::That(cell.GetValue(), Equals(5));
	}

	It(IsValidWhenItBelongsToThreeRegions)
	{
		Region r1, r2, r3, r4;
		Cell* cell=new Cell(1,1);
		r1.add(cell);
		Assert::That(!cell->isValid());
		r2.add(cell);
		r3.add(cell);
		Assert::That(cell->isValid());
		AssertThrows(std::out_of_range, r4.add(cell));
	}

	It(KnowsThatValueCanBeInvalidInRegion)
	{
		Cell* cell=new Cell(1,9);
		Region region;
		region.add(cell);
		cell->SetValue(5);
		Cell* cell2=new Cell(2,9);
		region.add(cell2);
		AssertThrows(std::logic_error, cell2->SetValue(5))
		cell2->SetValue(4);
		AssertThrows(std::logic_error, cell->SetValue(4));
	}

	It(KnowsPossibleValues)
	{
		Region r1, r2;
		for(int i = 1; i < 4; i++)
		{
			r1.add(new Cell(i,i,i));
		}
		Cell* cell = new Cell(1,2);
		r1.add(cell);
		Assert::That(cell->GetFreeValues(), HasLength(6));
		for(int i = 6; i<10; i++)
		{
			r2.add(new Cell(i,i,i));
		}
		r2.add(cell);
		Assert::That(cell->GetFreeValues(), HasLength(2));
	}

	It(CanCheckIfItIsSolvable)
	{
		Region r1;
		for(int i = 1; i < 8; i++)
		{
			r1.add(new Cell(i,i,i));
		}
		Cell* testcell = new Cell(1,2);
		r1.add(testcell);
		Assert::That(testcell->isSolvable());
		Cell* lastcell = new Cell(2,1,9);
		r1.add(lastcell);
		Assert::That(testcell->isSolvable());
		Region r2;
		r2.add(new Cell(1,1,8));
		r2.add(testcell);
		Assert::That(not testcell->isSolvable());
	}
};

