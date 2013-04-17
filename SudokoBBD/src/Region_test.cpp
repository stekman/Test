/*
 * Region_test.cpp
 *
 *  Created on: 10 apr 2013
 *      Author: stekman
 */

#include "igloo/igloo_alt.h"

#include <exception>
#include "Region.h"
#include "Cell.h"

using namespace igloo;

int nbrDeletes=0;

class TestCell: public Cell
    	{
    	public:
			TestCell(int& x, int& y): Cell(x,y) {}
    		~TestCell() { nbrDeletes++; }
    		static void initNbrDeletes() { nbrDeletes=0;}
    		static int getNbrDeletes() { return nbrDeletes;}
    	};

Describe(A_Region)
{
    It(CanReference9Values)
    {
        Region region;
        for(int i=0;i<9;i++)
        {
            Assert::That(!region.isValid());
            region.add(new Cell(i,i));
        }
        AssertThrows(std::overflow_error, region.add(new Cell(9,9)));
    }

    It(CanReturnCorrectCell)
    {
        Region region;
        for(int i=0;i<8;i++)
        {
            region.add(new Cell(i,i));
        }
        Cell* testcell = new Cell(1,2);
        region.add(testcell);
        Cell* comparecell = region.getCell(1,2);
        Assert::That(comparecell==testcell);
    }

    It(CannotReturnWrongCell)
    {
        Region region;
        for(int i=1;i<8;i++)
        {
            region.add(new Cell(i,i));
        }
        AssertThrows(std::logic_error, region.getCell(1,5));
    }

    It(CannotReturnIfInvalid)
    {
        Region region;
        for(int i=1;i<7;i++)
        {
            region.add(new Cell(i,i));
        }
        AssertThrows(std::logic_error, region.getCell(1,2));
    }

    It(CanListExistingValues)
    {
        Region region;
        for(int i=1;i<8;i++)
        {
            Cell* cell = new Cell(i,i);
            cell->setValue(i);
            region.add(cell);
            Assert::That(region.getValues(), Contains(i));
        }
        Assert::That(region.getValues(), HasLength(7));
    }

    It(CanListFreeValues)
    {
        Region region;
        for(int i=1;i<8;i++)
        {
            Cell* cell = new Cell(i,i);
            cell->setValue(i);
            region.add(cell);
            Assert::That(region.getFreeValues(), Is().Not().Containing(i));
        }
        Assert::That(region.getFreeValues(), HasLength(2));
    }

    It(CanCheckIfItHasAValue)
    {
    	Region region;
        for(int i=1;i<8;i++)
        {
            Cell* cell = new Cell(i,i);
            cell->setValue(i);
            region.add(cell);
        }
        Assert::That(region.hasValue(1) );
        Assert::That(not region.hasValue(8));
    }

    It(HasATypeAndPosition)
    {
    	Region region(Region::horizontal,1);
    	Assert::That(region.getType(), Equals(Region::horizontal));
    	Assert::That(region.getPosition(), Equals(1));
    }


    It(DeletesAbandonedCells)
    {



    	Region* region = new Region;
    	Region* region2 = new Region;
        for(int i=1;i<7;i++)
        {
            TestCell* cell = new TestCell(i,i);
            region->add(cell);
            region2->add(cell);
        }
        TestCell::initNbrDeletes();
        delete region;
        delete region2;
        Assert::That(TestCell::getNbrDeletes(), Equals(6));
    }
};
