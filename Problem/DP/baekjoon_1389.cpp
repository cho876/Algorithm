#include <iostream>
#include <cstdio>
#include <vector>

#define INF 9999999

using namespace std;

int main()
{
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<int>* v_adj = new vector<int>[nodes];

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			v_adj[i].push_back(INF);
		}
	}
	int from, to;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d", &from, &to);
		v_adj[from - 1][to-1] = 1;
		v_adj[to - 1][from-1] = 1;
	}

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			for (int k = 0; k < nodes; k++) {
				if (v_adj[j][k] > v_adj[j][i] + v_adj[i][k])
					v_adj[j][k] = v_adj[j][i] + v_adj[i][k];
			}
		}
	}
	
	vector<pair<int, int> > v_result;
	v_result.push_back(make_pair(0, INF));

	int result;
	for (int i = 0; i < nodes; i++) {
		result = 0;
		for (int j = 0; j < nodes; j++)
			result += v_adj[i][j];
		if (v_result[0].second > result) {
			v_result[0].first = i;
			v_result[0].second = result;
		}
	}

	printf("%d\n", v_result[0].first + 1);

	return 0;
}