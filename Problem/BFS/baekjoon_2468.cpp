#include<iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 101

using namespace std;

int map[MAX][MAX];
bool isVisited[MAX][MAX];
int moving[4][2] = { {1,0}, {-1,0},{0,1},{0,-1} };
int res;

void BFS(int height, int curX, int curY, int max) {
	isVisited[curX][curY] = true;

	int nextX, nextY;
	for (int i = 0; i < 4; i++) {
		nextX = curX + moving[i][0];
		nextY = curY + moving[i][1];

		if (nextX >= max || nextX < 0 || nextY >= max || nextY < 0)
			continue;
		else if (isVisited[nextX][nextY] || map[nextX][nextY] <= height)
			continue;

		BFS(height, nextX, nextY, max);
	}
}

int main() {
	int N;
	scanf("%d", &N);

	int spot;
	int minHeight = 0;
	int maxHeight = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &spot);
			map[i][j] = spot;

			maxHeight = max(maxHeight, spot);
			minHeight = min(minHeight, spot);
		}
	}

	for (int h = minHeight; h <= maxHeight; h++) {
		int tmpCnt = 0;
		memset(isVisited, false, sizeof(isVisited));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!isVisited[i][j] && map[i][j] > h) {
					BFS(h, i, j, N);
					tmpCnt++;
				}
			}
		}
		res = max(res, tmpCnt);
	}
	printf("%d\n", res);
	return 0;
}