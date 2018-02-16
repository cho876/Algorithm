#include <iostream>
#include <cstdio>
#include <vector>

#define NIL -1

using namespace std;

bool DFS(vector<int>* v_adj, int src, bool*& isMatched, int*& matched_R, int*& matched_L);
void findAns(vector<int>* v_adj, vector<int>* v_reverse, int src, bool*& isVisited_R, bool*& isVisited_L, int*& matched_R, int*& matched_L);

bool flag = true;
vector<int> ans;
int main() {
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<int>* v_adj = new vector<int>[nodes];
	vector<int>* v_reverse = new vector<int>[nodes];

	int row, col;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d", &row, &col);
		v_adj[row - 1].push_back(col - 1);
		v_reverse[col - 1].push_back(row - 1);
	}

	bool* isMatched = new bool[nodes];
	int* matched_R = new int[nodes];
	int* matched_L = new int[nodes];

	fill(matched_L, matched_L + nodes, NIL);
	fill(matched_R, matched_R + nodes, NIL);

	for (int i = 0; i < nodes; i++) {
		fill(isMatched, isMatched + nodes, false);
		DFS(v_adj, i, isMatched, matched_R, matched_L);
	}

	bool* isVisited_R = new bool[nodes];
	bool* isVisited_L = new bool[nodes];

	fill(isVisited_L, isVisited_L + nodes, false);
	fill(isVisited_R, isVisited_R + nodes, false);

	for (int i = 0; i < nodes; i++) {
		if (matched_L[i] == NIL) {
			findAns(v_adj, v_reverse, i, isVisited_R, isVisited_L, matched_R, matched_L);
		}
	}
	for (int i = 0; i < nodes; i++) {
		if (!isVisited_L[i]) {
			ans.push_back(i);
		}
	}

	printf("%d\n", ans.size());
	return 0;
}

void findAns(vector<int>* v_adj, vector<int>* v_reverse, int src, bool*& isVisited_R, bool*& isVisited_L, int*& matched_R, int*& matched_L) {
	if (flag) {
		isVisited_L[src] = true;
		int nextNode;
		for (int i = 0; i < v_adj[src].size(); i++) {
			nextNode = v_adj[src][i];

			if (!isVisited_R[nextNode]) {
				flag = false;
				findAns(v_adj, v_reverse, nextNode, isVisited_R, isVisited_L, matched_R, matched_L);
			}
		}
	}

	if (!flag) {
		isVisited_R[src] = flag = true;
		ans.push_back(src);

		int nextNode = matched_R[src];
		if (nextNode != NIL && !isVisited_L[nextNode]) {
			findAns(v_adj, v_reverse, nextNode, isVisited_R, isVisited_L, matched_R, matched_L);
		}
	}
}

bool DFS(vector<int>* v_adj, int src, bool*& isMatched, int*& matched_R, int*& matched_L) {
	if (!isMatched[src]) {
		isMatched[src] = true;

		int next_R;
		for (int i = 0; i < v_adj[src].size(); i++) {
			next_R = v_adj[src][i];

			if (matched_R[next_R] == NIL || DFS(v_adj, matched_R[next_R], isMatched, matched_R, matched_L)) {
				matched_R[next_R] = src;
				matched_L[src] = next_R;
				return true;
			}
		}
	}
	return false;
}