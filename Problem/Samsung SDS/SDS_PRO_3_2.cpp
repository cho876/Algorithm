#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

void initParent() {
	for (int i = 0; i < parent.size(); i++)
		parent[i] = i;
}

int find(int index) {
	if (parent[index] == index)
		return index;
	else
		return parent[index] = find(parent[index]);
}

void makeUnion(int from, int to) {
	int root1 = find(from);
	int root2 = find(to);

	if (root1 == root2)
		return;
	
	parent[root2] = root1;
}

int main() {
	int N, Q;
	scanf("%d%d", &N, &Q);
	parent.resize(N + 1);
	initParent();

	int command, from, to;
	for (int i = 0; i < Q; i++) {
		scanf("%d%d%d", &command, &from, &to);
		if (command == 0) {
			makeUnion(from, to);
		}
		else {
			if (find(parent[from]) == find(parent[to]))
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}