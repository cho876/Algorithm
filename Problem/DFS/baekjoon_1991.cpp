#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAX 26

using namespace std;

int tree[MAX][2];

void preOrder(int node) {
	if (node == (int)('.' - 'A'))
		return;

	printf("%c", node + 'A');
	preOrder(tree[node][0]);
	preOrder(tree[node][1]);
}

void inOrder(int node) {
	if (node == (int)('.' - 'A'))
		return;

	inOrder(tree[node][0]);
	printf("%c", node + 'A');
	inOrder(tree[node][1]);
}

void postOrder(int node) {
	if (node == (int)('.' - 'A'))
		return;

	postOrder(tree[node][0]);
	postOrder(tree[node][1]);
	printf("%c", node + 'A');
}

int main() {
	int n;
	scanf("%d", &n);

	char cen, lef, rig;
	for (int i = 0; i < n; i++) {
		cin >> cen >> lef >> rig;

		tree[cen - 'A'][0] = lef - 'A';
		tree[cen - 'A'][1] = rig - 'A';
	}
	preOrder(0);
	printf("\n");
	inOrder(0);
	printf("\n");
	postOrder(0);
	printf("\n");
}