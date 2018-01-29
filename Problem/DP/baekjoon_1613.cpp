#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<int>* v_adj = new vector<int>[nodes];

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++)
			v_adj[i].push_back(0);
	}

	int before, after;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d", &before, &after);
		v_adj[before - 1][after - 1] = -1;
		v_adj[after - 1][before - 1] = 1;
	}

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			for (int k = 0; k < nodes; k++) {
				if (v_adj[j][i] == -1 && v_adj[i][k] == -1)
					v_adj[j][k] = -1;
				else if (v_adj[j][i] == 1 && v_adj[i][k] == 1)
					v_adj[j][k] = 1;
			}
		}
	}

	int sets;
	scanf("%d", &sets);
	for (int i = 0; i < sets; i++) {
		scanf("%d%d", &before, &after);
		printf("%d\n", v_adj[before - 1][after - 1]);
	}

	return 0;
}