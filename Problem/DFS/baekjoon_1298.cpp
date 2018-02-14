#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define NIL -1

using namespace std;

bool BFS(vector<int>* v_adj, int src, bool*& isVisited, int*& match_R);

int main()
{
	int node_L, node_R;
	scanf("%d%d", &node_L, &node_R);
	vector<int>* v_adj = new vector<int>[node_L];

	int from, to;
	for (int i = 0; i < node_R; i++) {
		scanf("%d%d", &from, &to);
		v_adj[from - 1].push_back(to - 1);
	}

	bool* isVisited = new bool[node_L];
	int* match_R = new int[node_R];

	fill(match_R, match_R + node_R, NIL);


	int count = 0;

	for (int i = 0; i < node_L; i++) {
		fill(isVisited, isVisited + node_L, false);
		if (BFS(v_adj, i, isVisited, match_R))
			count++;
	}

	printf("%d\n", count);

	return 0;
}

bool BFS(vector<int>* v_adj, int src, bool*& isVisited, int*& match_R) {
	if (!isVisited[src]) {
		isVisited[src] = true;

		int next_R;
		for (int i = 0; i < v_adj[src].size(); i++) {
			next_R = v_adj[src][i];

			if (match_R[next_R] == NIL || BFS(v_adj, match_R[next_R], isVisited, match_R)) {
				match_R[next_R] = src;
				return true;
			}
		}
	}
	return false;

}