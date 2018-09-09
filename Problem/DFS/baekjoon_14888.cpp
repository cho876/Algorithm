#include <iostream>
#include <stdio.h>
#include <algorithm>

#define MAX 987654321
#define MIN -987654321
#define NODE 13

using namespace std;

int N;
int arr[NODE];
int plus_total, minus_total, multi_total, div_total;

int maxValue = MIN;
int minValue = MAX;

void dfs(int idx, int plus, int minus, int multi, int div, int total) {
	if (idx == N) {
		maxValue = max(maxValue, total);
		minValue = min(minValue, total);
		return;
	}
	else {
		if (plus < plus_total)
			dfs(idx + 1, plus + 1, minus, multi, div, total + arr[idx]);
		if (minus < minus_total)
			dfs(idx + 1, plus, minus + 1, multi, div, total - arr[idx]);
		if (multi < multi_total)
			dfs(idx + 1, plus, minus, multi + 1, div, total * arr[idx]);
		if (div < div_total)
			dfs(idx + 1, plus, minus, multi, div + 1, total / arr[idx]);
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	scanf("%d%d%d%d", &plus_total, &minus_total, &multi_total, &div_total);

	dfs(1, 0, 0, 0, 0, arr[0]);
	printf("%d\n%d\n", maxValue, minValue);
	
	return 0;
}