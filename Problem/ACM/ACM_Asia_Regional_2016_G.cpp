#include <iostream>

using namespace std;

struct Point {
	int row;
	int col;
};

class Maze {
private:
	int** map;
	bool** isVisited;
	int mapCol;
	int mapRow;

public:
	void createMap(int mapRow, int mapCol);
	bool pathExist(Point src, Point dst);
	bool pathExistRecur(Point curSrc, Point dst);
};


void Maze::createMap(int mapRow, int mapCol) {
	this->mapRow = mapRow;
	this->mapCol = mapCol;

	map = new int*[mapRow];
	isVisited = new bool*[mapRow];

	for (int i = 0; i < mapRow; i++) {
		map[i] = new int[mapCol];
		isVisited[i] = new bool[mapCol];
	}

	char input;
	for (int i = 0; i < mapRow; i++) {
		for (int j = 0; j < mapCol; j++) {
			cin >> input;
			int parse_int = input - 48;
			map[i][j] = parse_int;
			isVisited[i][j] = false;
		}
	}
}

bool Maze::pathExist(Point src, Point dst) {
	if (map[src.row][src.col] == 1)
		return false;
	else
		return pathExistRecur(src, dst);
}

bool Maze::pathExistRecur(Point curSrc, Point dst) {
	if (curSrc.row == dst.row)
		return true;

	else {
		isVisited[curSrc.row][curSrc.col] = true;
		Point curSpot;

		if (curSrc.row + 1 < mapRow) {    // Bottom
			if (map[curSrc.row + 1][curSrc.col] == 0 && isVisited[curSrc.row + 1][curSrc.col] == false) {
				curSpot.row = curSrc.row + 1;
				curSpot.col = curSrc.col;
				if (pathExistRecur(curSpot, dst))
					return true;
			}
		}
		if (curSrc.col + 1 < mapCol) {   // Right
			if (map[curSrc.row][curSrc.col + 1] == 0 && isVisited[curSrc.row][curSrc.col + 1] == false) {
				curSpot.row = curSrc.row;
				curSpot.col = curSrc.col + 1;
				if (pathExistRecur(curSpot, dst))
					return true;
			}
		}
		if (curSrc.col - 1 >= 0) {   // Left
			if (map[curSrc.row][curSrc.col - 1] == 0 && isVisited[curSrc.row][curSrc.col - 1] == false) {
				curSpot.row = curSrc.row;
				curSpot.col = curSrc.col - 1;
				if (pathExistRecur(curSpot, dst))
					return true;
			}
		}
		if (curSrc.row - 1 >= 0) {   // Top
			if (map[curSrc.row - 1][curSrc.col] == 0 && isVisited[curSrc.row - 1][curSrc.col] == false) {
				curSpot.row = curSrc.row - 1;
				curSpot.col = curSrc.col;
				if (pathExistRecur(curSpot, dst))
					return true;
			}
		}
		return false;
	}
}

int main() {
	Maze maze;
	Point src;
	Point dst;

	int mapRow, mapCol;
	cin >> mapRow >> mapCol;
	
	src.row = 0;
	dst.row = mapRow - 1;

	maze.createMap(mapRow, mapCol);

	for (int i = 0; i < mapCol; i++) {
		src.col = i;
		if (maze.pathExist(src, dst)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}