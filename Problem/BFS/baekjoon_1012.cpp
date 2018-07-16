#include <iostream>
#include <cstdio>
#include <vector>

#define MAX 51

using namespace std;

int map[MAX][MAX] = { 0, };
int moving[4][2] = { {1,0}, {-1,0},{0,1},{0,-1} };

void BFS(int curX, int curY, int maxX, int maxY) {
	map[curX][curY] = 2;

	int nextX, nextY;
	for (int i = 0; i < 4; i++) {
		nextX = curX + moving[i][0];
		nextY = curY + moving[i][1];

		if (nextX >= maxX || nextX < 0 || nextY >= maxY || nextY < 0)
			continue;

		if (map[nextX][nextY] != 1)
			continue;

		BFS(nextX, nextY, maxX, maxY);
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int M, N, K;
		scanf("%d%d%d", &M, &N, &K);

		int x, y;
		for (int i = 0; i < K; i++) {
			scanf("%d%d", &x, &y);
			map[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					BFS(i, j, N, M);
					cnt++;
				}
			}
		}
		printf("´ä: %d\n", cnt);
	}
	return 0;
}