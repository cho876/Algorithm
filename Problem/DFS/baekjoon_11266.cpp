#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<int>* v_adj, bool*& result, int index, bool*& isVisited, int*& parent, int*& low, int*& dfsNum);

int main() {
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<int>* v_adj = new vector<int>[nodes];

	int from, to;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d", &from, &to);
		v_adj[from - 1].push_back(to - 1);
		v_adj[to - 1].push_back(from - 1);
	}

	bool* isVisited = new bool[nodes];
	bool* result = new bool[nodes];
	int* parent = new int[nodes];
	int* low = new int[nodes];
	int* dfsNum = new int[nodes];

	for (int i = 0; i < nodes; i++) {
		isVisited[i] = false;
		result[i] = false;
		parent[i] = -1;
	}

	DFS(v_adj, result, 0, isVisited, parent, low, dfsNum);

	for (int i = 0; i < nodes; i++)
		if (result[i])
			printf("%d ", i+1);
	printf("\n");

	return 0;
}

void DFS(vector<int>* v_adj,bool*& result, int index, bool*& isVisited, int*& parent, int*& low, int*& dfsNum) {
	static int time = 0;
	int children = 0;

	isVisited[index] = true;
	low[index] = dfsNum[index] = ++time;

	int nextNode;
	for (int i = 0; i < v_adj[index].size(); i++) {
		nextNode = v_adj[index][i];
		if (!isVisited[nextNode]) {
			children++;
			parent[nextNode] = index;
			DFS(v_adj, result, nextNode, isVisited, parent, low, dfsNum);

			low[index] = min(low[index], low[nextNode]);

			if (parent[index] == -1 && children > 1)
				result[index] = true;

			if (parent[index] != -1 &&low[nextNode] >= dfsNum[index]) 
				result[index] = true;

		}
		else if (parent[index] != nextNode)
			low[index] = min(low[index], dfsNum[nextNode]);
	}
}