#include "Maze.h"


Maze::Maze() {}

/**
	Map Creation Functions

	param 1: Column length in map
	param 2: Row length in map
*/
void Maze::createMap(int mapCol, int mapRow) {
	this->mapCol = mapCol;
	this->mapRow = mapRow;

	map = new int*[mapRow];
	visited = new bool*[mapRow];

	for (int i = 0; i < mapCol; i++) {
		map[i] = new int[mapCol];
		visited[i] = new bool[mapCol];
	}

	for (int i = 0; i < mapRow; i++) {
		for (int j = 0; j < mapCol; j++) {
			cin >> map[i][j];
		}
	}
}

/**
	Make sure the origin and destination are open

	param 1: Starting point
	param 2: Destination point
*/
bool Maze::pathExist(Point src, Point dst) {
	for (int i = 0; i < mapRow; i++) {
		for (int j = 0; j < mapCol; j++) {
			visited[i][j] = false;
		}
	}

	if (map[src.row][src.col] == 1 || map[dst.row][dst.col] == 1)   // When the start or destination is blocked 
		return false;
	else
		return pathExistRecur(src, dst);
}

/**
	Recursive path search

	param 1: Current location point
	param 2: Destination point
*/
bool Maze::pathExistRecur(Point curSrc, Point dst) {
	visited[curSrc.row][curSrc.col] = true;
	if (curSrc.row == dst.row && curSrc.col == dst.col)
		return true;

	Point nextSpot;

	if (curSrc.row + 1 < mapRow) {  // Top navigation
		if (map[curSrc.row + 1][curSrc.col] == 0 && visited[curSrc.row + 1][curSrc.col] == false) {
			nextSpot.row = curSrc.row + 1;
			nextSpot.col = curSrc.col;
			if (pathExistRecur(nextSpot, dst))
				return true;
		}
	}

	if (curSrc.row - 1 >= 0) {   // Down navigation
		if (map[curSrc.row - 1][curSrc.col] == 0 && visited[curSrc.row - 1][curSrc.col] == false) {
			nextSpot.row = curSrc.row - 1;
			nextSpot.col = curSrc.col;
			if (pathExistRecur(nextSpot, dst))
				return true;
		}
	}

	if (curSrc.col + 1 < mapCol) {  // Right Navigate
		if (map[curSrc.row][curSrc.col + 1] == 0 && visited[curSrc.row][curSrc.col + 1] == false) {
			nextSpot.row = curSrc.row;
			nextSpot.col = curSrc.col + 1;
			if (pathExistRecur(nextSpot, dst))
				return true;
		}
	}

	if (curSrc.col - 1 >= 0) {    // Left navigation
		if (map[curSrc.row][curSrc.col - 1] == 0 && visited[curSrc.row][curSrc.col - 1] == false) {
			nextSpot.row = curSrc.row;
			nextSpot.col = curSrc.col - 1;
			if (pathExistRecur(nextSpot, dst))
				return true;
		}
	}
	return false;
}