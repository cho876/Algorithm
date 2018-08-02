#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 100000

using namespace std;

int arr[MAX];
int dist[MAX];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	dist[0] = arr[0];

	int maxValue = dist[0];
	for (int i = 1; i < n; i++) {
		dist[i] = max(dist[i - 1] + arr[i], arr[i]);
		maxValue = max(dist[i], maxValue);
	}

	printf("%d\n", maxValue);
}