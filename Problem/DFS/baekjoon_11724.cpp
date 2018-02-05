#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

#define NIL -1

using namespace std;

void DFS(vector<int>* v_adj, int index, vector<pair<int, int> >& v_info, bool*& isVisited, int& result);

stack<int> st;

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

	vector<pair<int, int> > v_info;
	v_info.resize(nodes);
	bool* isVisited = new bool[nodes];
	for (int i = 0; i < nodes; i++) {
		isVisited[i] = false;
		v_info[i].first = NIL;
	}
	int result = 0;

	for (int i = 0; i < nodes; i++) {
		if (v_info[i].first == NIL)
			DFS(v_adj, i, v_info, isVisited, result);
	}

	printf("%d\n", result);

	return 0;
}

void DFS(vector<int>* v_adj, int index, vector<pair<int, int> >& v_info, bool*& isVisited, int& result) {
	static int time = 0;

	v_info[index].first = v_info[index].second = ++time;
	isVisited[index] = true;
	st.push(index);

	int nextNode = 0;
	for (int i = 0; i < v_adj[index].size(); i++) {
		nextNode = v_adj[index][i];

		if (!isVisited[nextNode]) {
			DFS(v_adj, nextNode, v_info, isVisited, result);
			v_info[index].second = min(v_info[index].second, v_info[nextNode].second);
		}
		else {
			v_info[index].second = min(v_info[nextNode].first, v_info[index].second);
		}
	}

	if (v_info[index].first == v_info[index].second)
		result++;

	return;
}