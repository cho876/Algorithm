#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int zeroCnt;
int moving[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > >path;

void BFS(vector<int>*& point, int maxX, int maxY) {
	int curCnt, curX, curY, nextCnt, nextX, nextY;
	while (!path.empty()) {
		curCnt = path.top().first;
		curX = path.top().second.first;
		curY = path.top().second.second;
		path.pop();

		for (int i = 0; i < 4; i++) {
			nextX = curX + moving[i][0];
			nextY = curY + moving[i][1];

			if (nextX >= maxX || nextX < 0 || nextY >= maxY || nextY < 0)
				continue;
			
			if (point[nextY][nextX] == 0) {
				nextCnt = curCnt + 1;
				point[nextY][nextX] = 1;
				zeroCnt--;
				if (zeroCnt == 0) {
					printf("%d\n", nextCnt);
					return;
				}else
					path.push({ nextCnt, {nextX, nextY} });
			}
		}
	}
	printf("-1\n");
}

int main() {
	int x, y;
	scanf("%d%d", &x, &y);

	vector<int>* point = new vector<int>[y];

	int spot;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			scanf("%d", &spot);
			point[i].push_back(spot);

			if (spot == -1)
				continue;
			else if (spot == 1)
				path.push({ 0, {j,i} }); // cnt, x, y
			else if (spot == 0)
				zeroCnt++;
		}
	}
	if (zeroCnt == 0)
		printf("0\n");
	else
		BFS(point, x, y);
	
	return 0;
}