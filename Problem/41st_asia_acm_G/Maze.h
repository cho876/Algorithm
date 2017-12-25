#pragma once
#include <iostream>
#include <string>

using namespace std;

class Point {
public:
	int col;   // За
	int row;   // ї­
};

class Maze {
public:
	Maze();
	void createMap(int mapCol, int mapRow);
	bool pathExist(Point src, Point dst);
	bool pathExistRecur(Point curSrc, Point dst);

private:
	int mapCol;
	int mapRow;
	int** map;
	bool** visited;
};