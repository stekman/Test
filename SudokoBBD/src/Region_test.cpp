/*
 * Region_test.cpp
 *
 *  Created on: 10 apr 2013
 *      Author: stekman
 */

#include <exception>
#include "Region.h"
#include "Cell.h"
#include "igloo/igloo_alt.h"
using namespace igloo;

Describe(A_Region)
{
	It(CanReference9Values)
	{
		Region region();
		for(int i=0;i<9;i++)
		{
			Assert::That(!region.isValid());
			region.add(new Cell(i,i));
		}
		Assert::That(region.size(),Equals(9));
		AssertThrows(std::overflow_error, region.add(new Cell(9,9)));
	}

	It(CanReturnCorrectCell)
	{
		Region region();
		for(int i=0;i<8;i++)
		{
			region.add(new Cell(i,i));
		}
		Cell* testcell = new Cell(1,2);
		region.add(testcell);
		Cell* comparecell = region.getCell(1,2);
		Assert::That(comparecell==testcell);
	}

	It(CennotReturnWrongCell)
	{
		Region region();
		for(int i=0;i<8;i++)
		{
			region.add(new Cell(i,i));
		}
		Cell* testcell = new Cell(1,2);
		region.add(testcell);
		Cell* comparecell = region.getCell(1,1);
		Assert::That(comparecell==nullptr);
	}

	It(CannotReturnIfInvalid)
	{
		Region region();
		for(int i=0;i<7;i++)
		{
			region.add(new Cell(i,i));
		}
		Cell* testcell = new Cell(1,2);
		region.add(testcell);
		AssertThrow(std::logic_error, region.getCell(1,2));
	}
}
