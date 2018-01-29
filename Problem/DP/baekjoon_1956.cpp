#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 99999999
using namespace std;

int main()
{
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<int>* dist = new vector<int>[nodes];
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++)
			dist[i].push_back(INF);
	}

	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		dist[from - 1][to - 1] = weight;
	}

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			for (int k = 0; k < nodes; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k])
					dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}

	int result = INF;
	for (int i = 0; i < nodes; i++) 
		result = min(result, dist[i][i]);

	if (result == INF)
		printf("-1\n");
	else
		printf("%d\n", result);

	return 0;
}