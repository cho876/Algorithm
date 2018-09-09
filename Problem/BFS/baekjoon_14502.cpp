#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

#define MAX 8

using namespace std;

int N, M;
int map[MAX][MAX];
int tmpMap[MAX][MAX];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int ans;

void cpyMap(int(*tmpMap)[8], int(*map)[8]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			tmpMap[i][j] = map[i][j];
	}
}

void spread() {
	int spreadMap[MAX][MAX];
	cpyMap(spreadMap, tmpMap);

	queue<pair<int,int> > q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (spreadMap[i][j] == 2)
				q.push({ i,j });
		}
	}

	int curX, curY, nextX, nextY;
	while (!q.empty()) {
		curX = q.front().first;
		curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nextX = curX + dx[i];
			nextY = curY + dy[i];

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M) {
				if (spreadMap[nextX][nextY] == 0) {
					spreadMap[nextX][nextY] = 2;
					q.push({ nextX, nextY });
				}
			}
		}
	}

	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (spreadMap[i][j] == 0)
				tmp++;
		}
	}
	ans = max(ans, tmp);
}

void wall(int cnt) {
	if (cnt == 3) {
		spread();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmpMap[i][j] == 0) {
				tmpMap[i][j] = 1;
				wall(cnt + 1);
				tmpMap[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cpyMap(tmpMap, map);
				tmpMap[i][j] = 1;
				wall(1);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}