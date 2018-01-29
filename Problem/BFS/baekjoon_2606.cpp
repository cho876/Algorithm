#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<int>* v_adj, bool*& isVisited, int src);

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
	for (int i = 0; i < nodes; i++)
		isVisited[i] = false;

	BFS(v_adj, isVisited, 0);

	int count = 0;
	for (int i = 0; i < nodes; i++) {
		if (isVisited[i])
			count++;
	}

	printf("%d\n", count-1);

	return 0;
}

void BFS(vector<int>* v_adj, bool*& isVisited, int src) {
	priority_queue<int> q_list;
	q_list.push(src);

	int curNode, nextNode;
	while (!q_list.empty()) {
		curNode = q_list.top();
		q_list.pop();
		isVisited[curNode] = true;

		for (int i = 0; i < v_adj[curNode].size(); i++) {
			nextNode = v_adj[curNode][i];

			if (!isVisited[nextNode])
				q_list.push(nextNode);
		}
	}
}