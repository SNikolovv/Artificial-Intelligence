#pragma once
#include<iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include<array>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>

class Board
{
private:
	int table[3][3];
	int sizeOfBoard = 3;

	int xOfZero;
	int yOfZero;
	int heuristicValue;
	int distance;
	int emptySpaceMove;


public:
	Board();
	Board(int[3][3]);
	int getAt(int, int) const;
	int getHeuristic() const;
	int getXOfZero() const;
	int getYOfZero() const;
	int getDistance() const;
	int getEmptySpaceMove()const;
	void setXOfZero(int);
	void setYOfZero(int);
	void setDistance(int);
	void setHeuristic(int);
	void setEmptySpaceMove(int);
	void swapWithZero(int, int);
	void swapWithIndexes(int, int, int, int);
	bool compareWith(const Board& oth) const;
	void printBoard() const;

	bool operator< (const Board&) const;
	~Board();
};