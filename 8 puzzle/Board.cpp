#include "Board.h"

Board::Board()
{}

Board::Board(int target[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			table[i][j] = target[i][j];
			if (table[i][j] == 0)
			{
				xOfZero = i;
				yOfZero = j;
			}
		}
	}

	heuristicValue = 0;
	distance = 0;
	emptySpaceMove = -1;

}

int Board::getAt(int i, int j) const
{
	return table[i][j];
}

int Board::getHeuristic() const
{
	return heuristicValue;
}

int Board::getXOfZero() const
{
	return xOfZero;
}

int Board::getYOfZero() const
{
	return yOfZero;
}

int Board::getDistance() const
{
	return distance;
}

int Board::getEmptySpaceMove() const
{
	return emptySpaceMove;
}

void Board::setXOfZero(int x)
{
	xOfZero = x;
}

void Board::setYOfZero(int y)
{
	yOfZero = y;
}

void Board::setDistance(int value)
{
	distance = value;
}

bool Board::compareWith(const Board& oth) const 
{
	for (int i = 0; i < sizeOfBoard; i++)
	{
		for (int j = 0; j < sizeOfBoard; j++)
		{

			if (table[i][j] != oth.getAt(i, j))
			{
				return false;
			}
		}
	}

	return true;
}

void Board::setHeuristic(int heu)
{
	heuristicValue = heu;
}

void Board::setEmptySpaceMove(int empty)
{
	emptySpaceMove = empty;
}

void Board::swapWithZero(int newXofZero, int newYofZero)
{
	int temp = table[xOfZero][yOfZero];
	table[xOfZero][yOfZero] = table[newXofZero][newYofZero];
	table[newXofZero][newYofZero] = temp;

	xOfZero = newXofZero;
	yOfZero = newYofZero;
}

void Board::swapWithIndexes(int currEmptySpaceRow, int currEmptySpaceColumn, int newEmptySpaceRow, int newEmptySpaceColumn) {
	int temp = table[currEmptySpaceRow][currEmptySpaceColumn];
	table[currEmptySpaceRow][currEmptySpaceColumn] = table[newEmptySpaceRow][newEmptySpaceColumn];
	table[newEmptySpaceRow][newEmptySpaceColumn] = temp;
}





void Board::printBoard() const
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << table[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool Board::operator<(const Board& oth) const
{
	return (heuristicValue + distance) > (oth.getHeuristic() + oth.getDistance());
}


Board::~Board()
{
}
