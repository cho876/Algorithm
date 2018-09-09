#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>

#define MAX 10001

using namespace std;

int N;
int arr[MAX];

int cmpArr() {
	for (int i = N - 1; i > 0; i--) {
		if (arr[i - 1] > arr[i])
			return i - 1;
	}
	return -1;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int idx = cmpArr();

	if (idx != -1) {
		for (int i = N - 1; i > idx; i--) {
			if (arr[idx] > arr[i]) {
				int tmp = arr[idx];
				arr[idx] = arr[i];
				arr[i] = tmp;
				break;
			}
		}

		sort(arr + idx + 1, arr + N, greater<int>());

		for (int i = 0; i < N; i++)
			printf("%d ", arr[i]);
	}
	else
		printf("-1\n");

}