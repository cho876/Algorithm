#include <iostream>
#include <stdio.h>
#include <algorithm>

#define MAX 14

using namespace std;

int N;
int arr[MAX];
int isVisited[MAX];

void dfs(int curPos, int cnt) {
	if (curPos == N && cnt == 6) {
		for (int i = 0; i < N; i++) {
			if (isVisited[i])
				printf("%d ", arr[i]);
		}
		printf("\n");
	}
	if (curPos == N)
		return;

	isVisited[curPos] = true;
	dfs(curPos + 1, cnt + 1);
	isVisited[curPos] = false;
	dfs(curPos + 1, cnt);
}

int main() {
	while (1) {
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		dfs(0, 0);
		printf("\n");
	}
	return 0;
}