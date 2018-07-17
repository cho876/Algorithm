#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX 301
using namespace std;

int moving[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int map[MAX][MAX];
int arr[MAX][MAX];
int res = 0;

int LIS(int curRow, int curCol, int limit) {
	int nextRow, nextCol;
	if (arr[curRow][curCol] == 0) {
		arr[curRow][curCol] = 1;

		for (int i = 0; i < 4; i++) {
			nextRow = curRow + moving[i][0];
			nextCol = curCol + moving[i][1];

			if (nextRow >= limit || nextRow < 0 || nextCol >= limit || nextCol < 0)
				continue;

			if (map[nextRow][nextCol] > map[curRow][curCol])
				arr[curRow][curCol] = max(arr[curRow][curCol], LIS(nextRow, nextCol, limit) + 1);
		}
	}
	return arr[curRow][curCol];
}

int main() {
	int n;
	scanf("%d", &n);

	int weight;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &weight);
			map[i][j] = weight;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res = max(res, LIS(i, j, n));
		}
	}
	printf("%d\n", res);
	return 0;
}