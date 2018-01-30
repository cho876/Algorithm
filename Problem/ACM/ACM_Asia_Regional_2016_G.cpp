#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

bool isInRange(int curRow, int curCol, int nextRow, int nextCol);

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	int row, col;
	scanf("%d%d", &row, &col);
	vector<int>* map = new vector<int>[row];

	char index;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> index;
			map[i].push_back(index - '0');
		}
	}

	bool** isVisited = new bool*[row];
	for (int i = 0; i < row; i++) 
		isVisited[i] = new bool[col];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			isVisited[i][j] = false;
	}

	for (int i = 0; i < col; i++) {
		priority_queue<pair<int,int> > path;
		path.push(make_pair(0, i));

		int curRow, curCol, nextRow, nextCol;
		while (!path.empty()) {
			curRow = path.top().first;
			curCol = path.top().second;
			path.pop();

			if (!isInRange(curRow, curCol, row, col) || map[curRow][curCol] == 1)
				continue;

			if (isVisited[curRow][curCol])
				continue;

			isVisited[curRow][curCol] = true;

			if (curRow == row - 1) {
				printf("YES\n");
				return 0;
			}
			for (int i = 0; i < 4; i++) {
				nextRow = curRow + dy[i];
				nextCol = curCol + dx[i];

				if (!isInRange(nextRow, nextCol, row, col))
					continue;

				path.push(make_pair(nextRow, nextCol));
			}
		}
	}
	printf("NO\n");
	return 0;
}

bool isInRange(int curRow, int curCol, int mapRow, int mapCol) {
	if (curRow >= mapRow || curRow < 0 || curCol >= mapCol || curCol < 0)
		return false;
	return true;
}