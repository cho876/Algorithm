#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addEdges(vector<int>*& v_adj, int size);
void DFS(vector<int>*& v_adj, int index, bool*& isVisited, int*& parent, int*& dfsNum, int*& low);

int time = 0;

int main() {

	int nodes, edges;
	cin >> nodes >> edges;
	vector<int>* v_adj = new vector<int>[nodes];

	addEdges(v_adj, edges);

	bool* isVisited = new bool[nodes];
	int* parent = new int[nodes];
	int* dfsNum = new int[nodes];
	int* low = new int[nodes];

	for (int i = 0; i < nodes; i++) {
		isVisited[i] = false;
		low[i] = -1;
	}

	for (int i = 0; i < nodes; i++) {
		if (!isVisited[i])
			DFS(v_adj, i, isVisited, parent, dfsNum, low);
	}
}

void DFS(vector<int>*& v_adj, int index, bool*& isVisited, int*& parent, int*& dfsNum, int*& low) {
	isVisited[index] = true;
	dfsNum[index] = low[index] = time++;

	int nextNode;
	for (int i = 0; i < v_adj[index].size(); i++) {
		nextNode = v_adj[index][i];

		if (!isVisited[nextNode]) {
			parent[nextNode] = index;
			DFS(v_adj, nextNode, isVisited, parent, dfsNum, low);

			low[index] = min(low[index], low[nextNode]);

			if (low[index] < low[nextNode])
				cout << index << " " << nextNode;
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