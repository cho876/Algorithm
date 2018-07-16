#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 101

using namespace std;

int moving[4][2] = { {1,0},{-1,0}, {0,1},{0,-1} };
int map[MAX][MAX];
vector<int> res;

int BFS(int curX, int curY, int maxX, int maxY) {
	int cnt = 1;
	map[curX][curY] = 2;

	int nextX, nextY;
	for (int i = 0; i < 4; i++) {
		nextX = curX + moving[i][0];
		nextY = curY + moving[i][1];

		if (nextX >= maxX || nextX < 0 || nextY >= maxY || nextY < 0)
			continue;

		if (map[nextX][nextY] != 0)
			continue;

		cnt += BFS(nextX, nextY, maxX, maxY);
	}
	return cnt;
}

int main() {
	int M, N, K;
	scanf("%d%d%d", &M, &N, &K);

	int startX, startY, endX, endY;
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d%d", &startX, &startY, &endX, &endY);

		for (int m = startY; m <= endY-1; m++) {
			for (int n = startX; n <= endX-1; n++)
				map[m][n] = 1;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) {
				res.push_back(BFS(i, j, M, N));
			}
		}
	}
	printf("%d\n", res.size());

	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);

	printf("\n");
	return 0;
}