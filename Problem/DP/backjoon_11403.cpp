#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 9999999

using namespace std;

int main()
{
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<int>* dist = new vector<int>[nodes];

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			if (i == j)
				dist[i].push_back(0);
			else
				dist[i].push_back(INF);
		}
	}
	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		dist[from - 1][to - 1] = min(dist[from - 1][to - 1], weight);
	}

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			for (int k = 0; k < nodes; k++)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
		}
	}

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++)
			printf("%d ", dist[i][j]);
		printf("\n");
	}

	return 0;
}