#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addEdges(vector<int>*& v_adj, int size);
void DFS(vector<int>*& v_adj, int index, bool*& isVisited, bool*& isCut, int*& parent, int*& dfsNum, int*& low);

int main() {
	int nodes, edges;
	cin >> nodes >> edges;
	vector<int>* v_adj = new vector<int>[nodes];
	addEdges(v_adj, edges);

	bool* isVisited = new bool[nodes];
	bool* isCut = new bool[nodes];
	int* parent = new int[nodes];
	int* dfsNum = new int[nodes];
	int* low = new int[nodes];

	for (int i = 0; i < nodes; i++) {
		isVisited[i] = false;
		isCut[i] = false;
		parent[i] = -1;
	}

	for (int i = 0; i < nodes; i++) {
		if (!isVisited[i])
			DFS(v_adj, i, isVisited, isCut, parent, dfsNum, low);
	}

	for (int i = 0; i < nodes; i++) {
		if (isCut[i])
			cout << i << endl;
	}
}

void DFS(vector<int>*& v_adj, int index, bool*& isVisited, bool*& isCut, int*& parent, int*& dfsNum, int*& low) {
	isVisited[index] = true;
	dfsNum[index] = low[index] = index;

	int children = 0;
	int nextNode;
	for (int i = 0; i < v_adj[index].size(); i++) {
		nextNode = v_adj[index][i];

		if (!isVisited[nextNode]) {
			children++;
			parent[nextNode] = index;
			DFS(v_adj, nextNode, isVisited, isCut, parent, dfsNum, low);

			low[index] = min(low[index], low[nextNode]);

			if (parent[index] == -1 && children > 1)
				isCut[index] = true;
			if (parent[index] != -1 && dfsNum[index] <= low[nextNode])
				isCut[index] = true;
		}
		else if (parent[index] != nextNode)
			low[index] = min(low[index], low[nextNode]);
	}
}

void addEdges(vector<int>*& v_adj, int size) {
	int edge1, edge2;

	for (int i = 0; i < size; i++) {
		cin >> edge1 >> edge2;
		v_adj[edge1].push_back(edge2);
		v_adj[edge2].push_back(edge1);
	}
}