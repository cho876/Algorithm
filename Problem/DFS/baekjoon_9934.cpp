#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void DFS(vector<int> v_nodes, int index, int dist, int start, int end, vector<int>& v_result);

int main() {
	int height;
	cin >> height;

	int nodes = pow(2, height) - 1;

	vector<int> v_nodes;
	vector<int> v_result;

	v_nodes.resize(nodes);
	v_result.resize(nodes + 1);

	for (int i = 0; i < nodes; i++)
		cin >> v_nodes[i];

	DFS(v_nodes, 1, 0, 0, v_nodes.size() - 1, v_result);

	int counter = 1;
	for (int i = 1; i < v_result.size(); i++) {
		cout << v_result[i] << " ";

		if (i == counter) {
			cout << endl;
			counter = counter * 2 + 1;
		}
	}
}

void DFS(vector<int> v_nodes, int index, int dist, int start, int end, vector<int>& v_result)
{
	int mid = (start + end) / 2;
	dist = (end - start) / 2;

	if (dist == 1) {
		v_result[index] = v_nodes[mid];
		v_result[index * 2] = v_nodes[mid - 1];
		v_result[index * 2 + 1] = v_nodes[mid + 1];
	}
	else {
		v_result[index] = v_nodes[mid];
		DFS(v_nodes, index * 2, dist, start, mid - 1, v_result);
		DFS(v_nodes, index * 2 + 1, dist, mid + 1, end, v_result);
	}
}