#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX 10001

using namespace std;

int arr[MAX];
int dist[MAX];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	dist[1] = arr[1];
	dist[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		dist[i] = max(arr[i] + arr[i - 1] + dist[i - 3], arr[i] + dist[i - 2]);
		dist[i] = max(dist[i - 1], dist[i]);
	}

	printf("%d\n", dist[n]);
}