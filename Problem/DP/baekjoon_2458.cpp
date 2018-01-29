#include<iostream>
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
			v_adj[i].push_back(0);
	}

	int from, to;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d", &from, &to);
		v_adj[from-1][to-1] = 1;
	}

	int count = 0;
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			for (int k = 0; k < nodes; k++) {
				if (v_adj[j][i] && v_adj[i][k])
					v_adj[j][k] = 1;
			}
		}
	}


	int count1;
	int count2;
	for (int i = 0; i < nodes; i++) {
		count1 = 0;
		count2 = 0;
		for (int j = 0; j < nodes; j++) {
			if (v_adj[i][j])
				count1++;
			else if (v_adj[j][i])
				count2++;
		}
		if (count1 + count2 == nodes - 1)
			count++;
	}
	printf("%d\n", count);

	return 0;
}