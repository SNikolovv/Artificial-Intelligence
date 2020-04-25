#include "Solver.h"

Solver::Solver(int init[3][3])
{
	int result[3][3] = { { 1,2,3 }, { 4,5,6 }, { 7,8,0 } };
	target = Board(result);
	start = Board(init);
	calculateAndSetHeuristic(start);
}

void Solver::calculateAndSetHeuristic(Board& b)// Manhattan distance
{
	int cost = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) 
		{

		
			cost += calculateHeuristicForPosition(i, j, b.getAt(i,j));

		}
	}

	b.setHeuristic(cost);
}

int Solver::calculateHeuristicForPosition(int i, int j, int number)
{
	std::pair<int, int> targetIndex = findIndexOfNumberInTarget(number);
	return std::abs(targetIndex.first - i) + std::abs(targetIndex.second - j);
	
}

std::pair<int, int> Solver::findIndexOfNumberInTarget(int number)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			if (target.getAt(i, j) == number)
			{
				return std::make_pair(i, j);
			}
		}
	}
}

void Solver::printSolution(std::vector<Board>& allTable, int index, int count)
{
	
	if (allTable[index].getEmptySpaceMove() == -1)
	{
		std::cout << "Depth: ";
		std::cout << count << std::endl;
		std::cout << std::endl;
		return;
	}

	int currentLine = allTable[index].getXOfZero();
	int currentColumn = allTable[index].getYOfZero();
	int first = currentLine + emptySpaceMoves[allTable[index].getEmptySpaceMove()][0];
	int second = currentColumn + emptySpaceMoves[allTable[index].getEmptySpaceMove()][1];
	allTable[index].swapWithIndexes(currentLine, currentColumn, first, second);
	

	for (int i = index - 1; i >= 0; i--)
	{
		if (allTable[index].compareWith(allTable[i]))
		{
			printSolution(allTable, i, count + 1);
			allTable[index].printBoard();
			std::cout << "*********" << std::endl;
			return;
		}
	}

}

bool Solver::position(int newLine, int newColumn)
{
	return newLine < 0 || newLine >= 3 || newColumn < 0 || newColumn >= 3;
}



void Solver::AStar()
{
	std::vector<Board> visited;//passed tables
	std::priority_queue <Board> tableQueue;
	tableQueue.push(start);

	int currentLine;
	int currentColumn;
	int newLine;
	int newColumn;

	while (!tableQueue.empty())
	{
		Board currTable = tableQueue.top();
		
		tableQueue.pop();

		if (tableAlreadyPassed(currTable, visited)) 
		{
			continue;
		}

		visited.push_back(currTable);
		

		if (currTable.getHeuristic() == 0)
		{
			break;
		}

		currentLine = currTable.getXOfZero();
		currentColumn = currTable.getYOfZero();

		Board newTable = currTable;
		for (int i = 0; i< 4; i++)
		{
			newLine = currentLine + emptySpaceMoves[i][0];
			newColumn = currentColumn + emptySpaceMoves[i][1];

			if (position(newLine, newColumn))
				continue;


					int newHeurestic = currTable.getHeuristic() -
				calculateHeuristicForPosition(newLine, newColumn,
					currTable.getAt(newLine, newColumn)) +
				calculateHeuristicForPosition(currentLine, currentColumn,
					currTable.getAt(newLine, newColumn)) -
				calculateHeuristicForPosition(currentLine, currentColumn,
					currTable.getAt(currentLine, currentColumn)) +
				calculateHeuristicForPosition(newLine, newColumn,
					currTable.getAt(currentLine, currentColumn));

		

			newTable.setHeuristic(newHeurestic);
			newTable.setDistance(currTable.getDistance() + 1);

			
			newTable.swapWithIndexes(currentLine, currentColumn, newLine, newColumn);
			newTable.setXOfZero(newLine);
			newTable.setYOfZero(newColumn);
			newTable.setEmptySpaceMove( 4 - i - 1);

		

			tableQueue.push(newTable);
			
			newTable.swapWithIndexes(currentLine, currentColumn, newLine, newColumn);

		}
		
	}

	int len = visited.size();
	printSolution(visited, len - 1, 0);
	target.printBoard();
}

bool Solver::tableAlreadyPassed(const Board& b1, const std::vector<Board>& visited) const
{
	for (int i = 0; i < visited.size(); i++)
	{
		if (b1.compareWith(visited[i]))
		{
			return true;
		}
	}

	return false;
}

Solver::~Solver()
{
}
