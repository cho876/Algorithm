#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 26

using namespace std;

vector<int> house;

char buf[MAX];
int map[MAX][MAX];
int n;
int moving[4][2] = { {1,0},{-1,0}, {0,1},{0,-1} };
int res;

int BFS(int curX, int curY) {
	int cnt = 1;
	map[curX][curY] = 2;

	int nextX, nextY;
	for (int i = 0; i < 4; i++) {
		nextX = curX + moving[i][0];
		nextY = curY + moving[i][1];

		if (nextX >= n || nextX < 0 || nextY >= n || nextY < 0)
			continue;

		if (map[nextX][nextY] != 1)
			continue;

		cnt += BFS(nextX, nextY);
	}
	return cnt;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j < n; j++)
			map[i][j] = buf[j] - '0';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				house.push_back(BFS(i, j));
			}
		}
	}
	sort(house.begin(), house.end());

	printf("%d\n", house.size());
	for (int i = 0; i < house.size(); i++)
		printf("%d\n", house[i]);

	return 0;
}