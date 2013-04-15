/*
 * Board_test.cpp
 *
 *  Created on: 13 apr 2013
 *      Author: stekman
 */

#include <iostream>
#include <string>
#include "Board.h"
#include "igloo/igloo_alt.h"
#include "Region.h"
#include "Cell.h"

using namespace igloo;

Describe(A_Board)
{
	It(CanHave9x9cells)
	{
		Board board;
		for(int x=1; x<=9; x++)
			for(int y=1; y<=9; y++)
				board.add(new Cell(x,y));
		AssertThrows(std::overflow_error, board.add(new Cell(1,1)));
	}

	It(CanHave3x9regions)
	{
		Board board;
		for(int group = 0; group<3; group++)
			for(int region = 0; region<9; region++)
				board.add(new Region);
		AssertThrows(std::overflow_error, board.add(new Region))
	}

	It(Gets3x9RegionsWhenSetup)
	{
		Board board;
		board.setup();
		Assert::That(board.GetRegions(), HasLength(3*9));
	}

	It(GetsRegionsFromCoordinates)
	{
		Board board;
		board.setup();
		list<Region*> regions=board.GetRegions(5,5);
		Assert::That(regions, HasLength(3));
		int areaposition=0;
		for(auto region: regions)
			if(region->getType()==Region::area)
				areaposition = region->getPosition();
		Assert::That(areaposition, Equals(5));
	}

	It(GetsCellsFromCoordinates)
	{
		Board board;
		board.setup();
		Cell* cell = board.getCell(5,5);
		cell->setValue(5);
		Cell* testCell = board.getCell(5,5);
		Assert::That(testCell->getValue(), Equals(5));
	}

	It(CannotGetCellsFromWrongCoordinates)
	{
		Board board;
		board.setup();
		AssertThrows(std::logic_error, board.getCell(10,10));
	}

	It(CanCheckIfACellHasAPossibleValue)
	{
		Board board;
		int boardvalues [9][9] =
			   {{4,3,5,2,6,9,7,8,1},
                {6,8,2,5,7,1,4,9,3},
                {1,9,7,8,3,4,5,6,2},
                {8,2,6,1,9,5,3,4,7},
                {3,7,4,6,8,2,9,1,5},
                {9,5,1,7,4,3,6,2,8},
                {5,1,9,3,2,6,8,7,4},
                {2,4,8,9,5,7,0,3,6},
                {7,6,3,4,1,8,2,5,9}};
		board.setup(boardvalues);
		Cell* testcell= board.getCell(8,7);
		Assert::That(testcell->getValue(), Equals(0));
		Assert::That(testcell->isSolvable());
	}

	It(CanCheckIfAnAlmostFinishedSudokoIsSolvable)
	{
		Board board;
		int boardvalues [9][9] =
			   {{4,3,5,2,6,9,7,8,1},
                {6,8,2,5,7,1,4,9,3},
                {1,9,7,8,3,4,5,6,2},
                {8,2,6,1,9,5,3,4,7},
                {3,7,4,6,8,2,9,1,5},
                {9,5,1,7,4,3,6,2,8},
                {5,1,9,3,2,6,8,7,4},
                {2,4,8,9,5,7,0,3,6},
                {7,6,3,4,1,8,2,5,9}};
		board.setup(boardvalues);
		Assert::That(not board.isUnsolvable());
	}

	It(CanSolveASudoko)
	{
		Board board;
		int sudoko[9][9]={{0,0,0,2,6,0,7,0,1},
		                  {6,8,0,0,7,0,0,9,0},
		                  {1,9,0,0,0,4,5,0,0},
		                  {8,2,0,1,0,0,0,4,0},
		                  {0,0,4,6,0,2,9,0,0},
		                  {0,5,0,0,0,3,0,2,8},
		                  {0,0,9,3,0,0,0,7,4},
		                  {0,4,0,0,5,0,0,3,6},
		                  {7,0,3,0,1,8,0,0,0}};
		board.setup(sudoko);
		board.solve();
		Board correct;
		int correctsudoko [9][9] =
			   {{4,3,5,2,6,9,7,8,1},
                {6,8,2,5,7,1,4,9,3},
                {1,9,7,8,3,4,5,6,2},
                {8,2,6,1,9,5,3,4,7},
                {3,7,4,6,8,2,9,1,5},
                {9,5,1,7,4,3,6,2,8},
                {5,1,9,3,2,6,8,7,4},
                {2,4,8,9,5,7,1,3,6},
                {7,6,3,4,1,8,2,5,9}};
		correct.setup(correctsudoko);

	}

	It(CanSolveAnAlmostSolvedSudoko)
	{
		Board board, correct;
		int boardvalues [9][9] =
			   {{4,3,5,2,6,9,7,8,1},
                {6,8,2,5,7,1,4,9,3},
                {1,9,7,8,3,4,5,6,2},
                {8,2,6,1,9,5,3,4,7},
                {3,7,4,6,8,2,9,1,5},
                {9,5,1,7,4,3,6,2,8},
                {5,1,9,3,2,6,8,7,4},
                {2,4,8,9,5,7,0,3,6},
                {7,6,3,4,1,8,2,5,9}};
		board.setup(boardvalues);
		int correctvalues [9][9] =
			   {{4,3,5,2,6,9,7,8,1},
                {6,8,2,5,7,1,4,9,3},
                {1,9,7,8,3,4,5,6,2},
                {8,2,6,1,9,5,3,4,7},
                {3,7,4,6,8,2,9,1,5},
                {9,5,1,7,4,3,6,2,8},
                {5,1,9,3,2,6,8,7,4},
                {2,4,8,9,5,7,1,3,6},
                {7,6,3,4,1,8,2,5,9}};
		correct.setup(correctvalues);
		board.solve();
		std::string boardstring= std::string(board);
		std::string correctstring= std::string(correct);
		Assert::That(boardstring, Equals(correctstring));;
		Assert::That(board==correct);
	}

	It(CanSolveAHardSudoko)
	{
		Board board;
		int boardvalues[9][9] =
			{
			 {0,0,9, 2,0,0, 0,0,8},
			 {6,2,0, 0,0,0, 0,0,0},
			 {0,0,7, 4,0,6, 1,0,0},

			 {0,0,0, 0,0,7, 0,4,0},
			 {1,8,0, 0,0,0, 7,0,9},
			 {0,7,0, 8,0,0, 0,0,0},

			 {0,0,2, 1,0,3,	9,0,0},
			 {0,0,0, 0,0,0, 0,5,1},
			 {7,0,0, 0,0,8,	3,0,0}
			};
		board.setup(boardvalues);
		board.solve();
		Assert::That(board.isSolved());
	}
};
