#include"Solver.h"
#include "Solvable.h"


int main()
{

	std::cout << "Enter digits from 0 to 8:" << std::endl;
	int matrix[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			std::cin >> matrix[i][j];
		}
	}

	if (isSolvable(matrix))
	{
		Solver s(matrix);
		s.AStar();
	}
	else
	{
		std::cout << "No solution!" <<std::endl;
	}


	return 0;
}