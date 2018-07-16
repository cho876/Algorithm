#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>

#define MAX 301

using namespace std;

priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > path;
bool isVisited[MAX][MAX];
int moving[8][2] = { {1,2},{2,1},{-1,-2},{-2,-1},{-1,2},{-2,1},{1,-2},{2,-1} };

void BFS(int dstX, int dstY, int max) {
	while (!path.empty()) {
		int curX, curY, curCnt, nextX, nextY, nextCnt;
		curCnt = path.top().first;
		curX = path.top().second.first;
		curY = path.top().second.second;
		path.pop();

		for (int i = 0; i < 8; i++) {
			nextX = curX + moving[i][0];
			nextY = curY + moving[i][1];

			if (nextX >= max || nextX < 0 || nextY >= max || nextY < 0)
				continue;

			else if (isVisited[nextY][nextX])
				continue;

			nextCnt = curCnt + 1;
			if (nextX == dstX && nextY == dstY) {
				printf("%d\n", nextCnt);
				return;
			}
			isVisited[nextY][nextX] = true;
			path.push({ nextCnt, {nextX, nextY} });
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int length;
		scanf("%d", &length);

		int startX, startY, dstX, dstY;
		scanf("%d%d%d%d", &startX, &startY, &dstX, &dstY);

		memset(isVisited, false, sizeof(isVisited));

		isVisited[startY][startX] = true;

		if (startX == dstX && startY == dstY)
			printf("0\n");
		else {
			path.push({ 0, {startX, startY} });
			BFS(dstX, dstY, length);
		}
		while (!path.empty())
			path.pop();
	}
	return 0;
}