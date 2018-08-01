#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>

#define MAX 5000000

using namespace std;

int nodes[MAX];
int maxNode;

int getLeft(int index) {
	return index * 2 + 1;
}

int getRight(int index) {
	return index * 2;
}

int DP(int index) {
	if (index >= maxNode)
		return 0;
	else {
		int leftValue = DP(getLeft(index)) + nodes[getLeft(index)];
		int rightValue = DP(getRight(index)) + nodes[getRight(index)];

		int maxValue = max(leftValue, rightValue);
		int diff = abs(leftValue - rightValue);

		if (leftValue > rightValue)
			nodes[getRight(index)] += diff;

		else if (rightValue > leftValue)
			nodes[getLeft(index)] += diff;

		return maxValue;
	}
}

int main() {
	int height;
	scanf("%d", &height);

	maxNode = pow(2, height + 1);

	for (int i = 2; i < maxNode; i++)
		scanf("%d", &nodes[i]);

	DP(1);

	int res = 0;
	for (int i = 1; i < maxNode; i++)
		res += nodes[i];

	printf("%d\n", res);
}