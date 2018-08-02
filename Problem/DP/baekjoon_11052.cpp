#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX 1001

using namespace std;

int fish[MAX];
int sum[MAX];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &fish[i]);

	sum[1] = fish[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++)
			sum[i] = max(sum[i], sum[i - j] + fish[j]);
		sum[i] = max(sum[i], fish[i]);
	}

	printf("%d\n", sum[n]);
}