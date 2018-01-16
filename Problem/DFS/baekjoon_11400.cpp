#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

void DFS(vector<int>* v_adj, int index, bool*& isVisited, int*& parent, int*& dfsNum, int*& low, vector<pair<int, int> >& v_result);

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;
	vector<int>* v_adj = new vector<int>[nodes];

	int from, to;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d", &from, &to);
		v_adj[from - 1].push_back(to - 1);
		v_adj[to - 1].push_back(from - 1);
	}

	int* parent = new int[nodes];
	int* dfsNum = new int[nodes];
	int* low = new int[nodes];
	bool* isVisited = new bool[nodes];

	for (int i = 0; i < nodes; i++) {
		parent[i] = -1;
		isVisited[i] = false;
	}

	vector<pair<int, int> > v_result;

	for (int i = 0; i < nodes; i++) {
		if (!isVisited[i])
			DFS(v_adj, i, isVisited, parent, dfsNum, low, v_result);
	}

	sort(v_result.begin(), v_result.end());

	printf("%d\n", v_result.size());
	for (int i = 0; i < v_result.size(); i++)
		printf("%d %d\n", v_result[i].first, v_result[i].second);

	return 0;
}

void DFS(vector<int>* v_adj, int index, bool*& isVisited, int*& parent, int*& dfsNum, int*& low, vector<pair<int, int> >& v_result) {
	isVisited[index] = true;

	static int time = 0;

	dfsNum[index] = low[index] = ++time;

	int nextNode;
	for (int i = 0; i < v_adj[index].size(); i++) {
		nextNode = v_adj[index][i];

		if (!isVisited[nextNode]) {
			parent[nextNode] = index;
			DFS(v_adj, nextNode, isVisited, parent, dfsNum, low, v_result);

			low[index] = min(low[index], low[nextNode]);

			if (dfsNum[index] < low[nextNode])
				v_result.push_back(make_pair(min(index + 1, nextNode + 1), max(index + 1, nextNode + 1)));
		}
		else if (parent[index] != nextNode)
			low[index] = min(low[index], low[nextNode]);
	}
}