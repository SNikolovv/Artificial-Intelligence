#pragma once
#include"Board.h"
#include<utility>

class Solver
{
	private :
		Board target;
		Board start;
		int emptySpaceMoves[4][2] = { {-1, 0}, {0, 1}, {0, -1}, {1, 0} };
	


	public:
		Solver(int[3][3]);
		void calculateAndSetHeuristic(Board& b);
		int calculateHeuristicForPosition(int, int, int);
		std::pair<int, int> findIndexOfNumberInTarget(int);
		void AStar();
		bool tableAlreadyPassed(const Board&, const std::vector<Board>&)const;
		void printSolution(std::vector<Board>&,int,int);
		bool position(int, int);
		~Solver();
};