#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		int nodes, edges;
		scanf("%d%d", &nodes, &edges);
		vector<int>* v_adj = new vector<int>[nodes];

		int from, to;
		for (int i = 0; i < edges; i++) {
			scanf("%d%d", &from, &to);
			v_adj[from - 1].push_back(to - 1);
			v_adj[to - 1].push_back(from - 1);
		}

		printf("%d\n", nodes - 1);
	}

	return 0;
}