#include <iostream>
#include <cstdio>
#include <vector>

#define NIL -1

using namespace std;

bool DFS(vector<int>* v_adj, int src, bool*& isVisited, int*& matched_R);
void makeEdge(vector<int>*& v_adj, int size, char** map, int** arr_row, int** arr_col);

int rowCnt = 0;
int colCnt = 0;

int main() {
	int nodes;
	scanf("%d", &nodes);

	char ** map = new char*[nodes];
	int** arr_row = new int*[nodes];
	int** arr_col = new int*[nodes];

	for (int i = 0; i < nodes; i++) {
		map[i] = new char[nodes];
		arr_row[i] = new int[nodes];
		arr_col[i] = new int[nodes];
	}

	for (int i = 0; i < nodes; i++) {
		fill(arr_row[i], arr_row[i] + nodes, NIL);
		fill(arr_col[i], arr_col[i] + nodes, NIL);
	}

	for (int i = 0; i < nodes; i++) {
		scanf("%s", map[i]);
		for (int j = 0; j < nodes; j++) {
			if (map[i][j] == 'X')
				rowCnt++;
			else
				arr_row[i][j] = rowCnt;
		}
		rowCnt++;
	}

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			if (map[j][i] == 'X')
				colCnt++;
			else
				arr_col[j][i] = colCnt;
		}
		colCnt++;
	}
	
	vector<int>* v_adj = new vector<int>[rowCnt];
	makeEdge(v_adj, nodes, map, arr_row, arr_col);
	bool* isVisited = new bool[rowCnt];
	int* matched_R = new int[colCnt];

	fill(matched_R, matched_R + colCnt, NIL);

	int count = 0;
	for (int i = 0; i < rowCnt; i++) {
		fill(isVisited, isVisited + rowCnt, false);
		if (DFS(v_adj, i, isVisited, matched_R))
			count++;
	}

	printf("%d\n", count);
	return 0;
}

bool DFS(vector<int>* v_adj, int src, bool*& isVisited, int*& matched_R) {
	if (!isVisited[src]) {
		isVisited[src] = true;

		int next_R;
		for (int i = 0; i < v_adj[src].size(); i++) {
			next_R = v_adj[src][i];

			if (matched_R[next_R] == NIL || DFS(v_adj, matched_R[next_R], isVisited, matched_R)) {
				matched_R[next_R] = src;
				return true;
			}
		}
	}
	return false;
}

void makeEdge(vector<int>*& v_adj, int size, char** map, int** arr_row, int** arr_col) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[i][j] == '.')
				v_adj[arr_row[i][j]].push_back(arr_col[i][j]);
		}
	}
}