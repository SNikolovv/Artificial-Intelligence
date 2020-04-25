#include "Solvable.h"
int getInvCount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i + 1; j < 9; j++)
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
    return inv_count;
}

bool isSolvable(int puzzle[3][3])
{ 
    int invCount = getInvCount((int*)puzzle);
    return (invCount % 2 == 0);
}