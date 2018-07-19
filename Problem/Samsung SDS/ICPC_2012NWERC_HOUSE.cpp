#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 10000000

using namespace std;

int main() {
	int X, N;
	scanf("%d%d", &X, &N);

	vector<int> values;
	int value;
	for (int i = 0; i < N; i++) {
		scanf("%d", &value);
		values.push_back(value);
	}
	sort(values.begin(), values.end());

	int base = X * MAX;

	int leftIndex = 0;
	int rightIndex = N - 1;
	int resLeft = -1;
	int resRight = -1;

	while (leftIndex < rightIndex) {
		if (values[leftIndex] + values[rightIndex] == base) {
			resLeft = values[leftIndex];
			resRight = values[rightIndex];
			break;
		}
		else if (values[leftIndex] + values[rightIndex] < base)
			leftIndex++;
		else
			rightIndex--;
	}

	if (resLeft == -1)
		printf("danger\n");
	else
		printf("yes %d %d\n", resLeft, resRight);

	return 0;
}