#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int row, col;
	scanf("%d", &row);
	col = row;

	vector<int> v_result(row);
	vector<int>* v_adj = new vector<int>[row];


	int value;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &value);
			v_adj[i].push_back(value);
		}
	}

	for (int i = 1; i < row; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				v_adj[i][j] = v_adj[i - 1][j] + v_adj[i][j];
			else if (j == i)
				v_adj[i][j] = v_adj[i - 1][j - 1] + v_adj[i][j];
			else
				v_adj[i][j] = max(v_adj[i - 1][j], v_adj[i - 1][j - 1]) + v_adj[i][j];
		}
	}

	int maxValue = 0;
	for (int i = 0; i < row; i++) {
		maxValue = max(v_adj[row - 1][i], maxValue);
	}

	printf("%d\n", maxValue);
	return 0;
}