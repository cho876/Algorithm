/**
	The 41st Annual ACM
	Asia Regional-Daejeon
	ASIA Regional
	
	Probelm G (Percolation)
*/

#include <iostream>

using namespace std;

class Point {
public:
	int row;
	int col;
};

class Maze {
public:
	Maze();
	void createMap(int mapRow, int mapCol);
	bool pathExist(Point src, Point dst);
	bool pathExistRecur(Point curSrc, Point dst);
	bool getVisited(int row, int col);

private:
	int mapRow;
	int mapCol;
	int** map;
	bool** visited;
};

Maze::Maze() {}

/**
	Map Creation Functions

	param 1: Column length in map
	param 2: Row length in map
*/
void Maze::createMap(int mapRow, int mapCol) {
	this->mapRow = mapRow;
	this->mapCol = mapCol;

	map = new int*[mapRow];
	visited = new bool*[mapRow];

	char k;

	for (int i = 0; i < mapRow; i++) {
		map[i] = new int[mapCol];
		visited[i] = new bool[mapCol];
	}

	for (int i = 0; i < mapRow; i++) {
		for (int j = 0; j < mapCol; j++)
			visited[i][j] = false;
	}

	for (int i = 0; i < mapRow; i++) {
		for (int j = 0; j < mapCol; j++) {
			cin >> k;
			map[i][j] = int(k - 48);
		}
	}
}

/**
	Make sure the origin and destination are open

	param 1: Starting point
	param 2: Destination point
*/
bool Maze::pathExist(Point src, Point dst) {
	if (map[src.row][src.col] == 1)
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
	if (curSrc.row == dst.row)
		return true;


	visited[curSrc.row][curSrc.col] = true;

	Point nextSpot;
	if (curSrc.row + 1 < mapRow) {  // Down navigation
		if (map[curSrc.row + 1][curSrc.col] == 0 && visited[curSrc.row + 1][curSrc.col] == false) {
			nextSpot.row = curSrc.row + 1;
			nextSpot.col = curSrc.col;
			if (pathExistRecur(nextSpot, dst))
				return true;
		}
	}

	if (curSrc.row - 1 >= 0) {   // Top navigation
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

bool Maze::getVisited(int row, int col) {
	return visited[row][col];
}

int main()
{
	Maze maze;
	Point src, dst;

	int mapRow, mapCol;
	cin >> mapRow >> mapCol;
	maze.createMap(mapRow, mapCol);

	src.row = 0;
	dst.row = mapRow - 1;

	for (int start = 0; start < mapCol; start++) {  // All the topmost rows of the map
		src.col = start;

		if (!maze.getVisited(src.row, src.col)) { // False if you have already visited
			if (maze.pathExist(src, dst)) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}