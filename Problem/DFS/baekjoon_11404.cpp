#include <iostream>
#include <vector>
#include <algorithm>

#define INF 99999999

using namespace std;

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;
	vector<int>* v_nodes = new vector<int>[nodes];

	for (int i = 0; i < nodes; i++) {
		v_nodes[i].resize(nodes);
		for (int j = 0; j < nodes; j++)
			v_nodes[i][j] = (i == j) ? 0 : INF;
	}


	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to >> weight;
		v_nodes[from - 1][to - 1] = min(v_nodes[from - 1][to - 1], weight);
	}

	for (int k = 0; k < nodes; k++) {
		for (int i = 0; i < nodes; i++) {
			for (int j = 0; j < nodes; j++)
				v_nodes[i][j] = min(v_nodes[i][j], v_nodes[i][k] + v_nodes[k][j]);
		}
	}

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++)
			cout << v_nodes[i][j] << " ";
		cout << endl;
	}

	return 0;
}