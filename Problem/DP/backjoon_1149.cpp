#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int map[MAX][3];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", &map[i][j]);

		map[i][0] += min(map[i - 1][1], map[i - 1][2]);
		map[i][1] += min(map[i - 1][0], map[i - 1][2]);
		map[i][2] += min(map[i - 1][0], map[i - 1][1]);
	}

	int res = min(min(map[n][0], map[n][1]), map[n][2]);
	printf("%d\n", res);
}