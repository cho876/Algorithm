#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

#define NIL -1

using namespace std;

void DFS(vector<int>* v_adj, int index, vector<pair<int, int> >& v_info, bool*& isContained);

stack<int> st;
vector<vector<int> > v_result;

int main() {
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<int>* v_adj = new vector<int>[nodes];

	int from, to;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d", &from, &to);
		v_adj[from - 1].push_back(to - 1);
	}

	vector<pair<int, int> > v_info;
	v_info.resize(nodes);
	bool* isContained = new bool[nodes];

	for (int i = 0; i < nodes; i++) {
		isContained[i] = false;
		v_info[i].first = NIL;
	}

	for (int i = 0; i < nodes; i++) {
		if (v_info[i].first == NIL)
			DFS(v_adj, i, v_info, isContained);
	}

	printf("%d\n", v_result.size());
	sort(v_result.begin(), v_result.end());

	for (int i = 0; i < v_result.size(); i++) {
		for (int j = 0; j < v_result[i].size(); j++)
			printf("%d ", v_result[i][j]);
		printf("-1\n");
	}

	return 0;
}

void DFS(vector<int>* v_adj, int index, vector<pair<int, int> >& v_info, bool*& isContained) {
	static int time = 0;

	v_info[index].first = v_info[index].second = ++time;
	isContained[index] = true;
	st.push(index);

	int nextNode;
	for (int i = 0; i < v_adj[index].size(); i++) {
		nextNode = v_adj[index][i];

		if (v_info[nextNode].first == NIL) {
			DFS(v_adj, nextNode, v_info, isContained);
			v_info[index].second = min(v_info[index].second, v_info[nextNode].second);
		}
		else if (isContained[nextNode])
			v_info[index].second = min(v_info[index].second, v_info[nextNode].first);
	}

	vector<int> v_local;
	int value = 0;
	if (v_info[index].first == v_info[index].second) {
		while (st.top() != index) {
			value = st.top();
			v_local.push_back(value + 1);
			isContained[value] = false;
			st.pop();
		}
		value = st.top();
		v_local.push_back(value + 1);
		isContained[value] = false;
		st.pop();

		sort(v_local.begin(), v_local.end());
		v_result.push_back(v_local);
	}
}