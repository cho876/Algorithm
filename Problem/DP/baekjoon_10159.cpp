#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<int>* v_adj = new vector<int>[nodes];

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++)
			if (i == j)
				v_adj[i].push_back(1);
			else
				v_adj[i].push_back(0);
	}

	int from, to;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d", &from, &to);
		v_adj[from - 1][to - 1] = 1;
	}


	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			for (int k = 0; k < nodes; k++) {
				if (v_adj[j][i]  && v_adj[i][k])
					v_adj[j][k] = 1;
			}
		}
	}

	int count;
	for (int i = 0; i < nodes; i++) {
		count = 0;
		for (int j = 0; j < nodes; j++) {
			if (!v_adj[i][j] && !v_adj[j][i])
				count++;
		}
		printf("%d\n", count);
	}

	return 0;
}