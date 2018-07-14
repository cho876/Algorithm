#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_NODES 100000

using namespace std;

int parent[MAX_NODES + 1][21];

void initParent(bool*& isVisited, int*& depth, vector<int>* v_adj, int curIndex, int curDepth) {
	isVisited[curIndex] = true;
	depth[curIndex] = curDepth;

	for (int nextIndex : v_adj[curIndex]) {
		if (isVisited[nextIndex])
			continue;

		parent[nextIndex][0] = curIndex;
		initParent(isVisited, depth, v_adj, nextIndex, curDepth + 1);
	}
}

void fillParent(int nodes) {
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= nodes; j++)
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
	}
}

int lca(int* depth, int from, int to) {
	if (depth[from] > depth[to])
		swap(from, to);

	for (int i = 20; i >= 0; i--) {
		if (depth[to] - depth[from] >= (1 << i))
			to = parent[to][i];
	}

	if (from == to)
		return from;

	for (int i = 20; i >= 0; i--) {
		if (parent[from][i] != parent[to][i]) {
			from = parent[from][i];
			to = parent[to][i];
		}
	}

	return parent[from][0];
}

int main() {
	int nodes;
	scanf("%d", &nodes);
	
	vector<int>* v_adj = new vector<int>[nodes + 1];

	int from, to;
	for (int i = 0; i < nodes - 1; i++) {
		scanf("%d%d", &from, &to);
		v_adj[from].push_back(to);
		v_adj[to].push_back(from);
	}

	bool* isVisited = new bool[nodes + 1];
	int* depth = new int[nodes + 1];
	fill(isVisited, isVisited + nodes + 1, false);
	fill(depth, depth + nodes + 1, 0);

	initParent(isVisited, depth, v_adj, 1, 0);
	fillParent(nodes);

	int cnt;
	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d%d", &from, &to);
		printf("%d\n", lca(depth, from, to));
	}
	return 0;
}