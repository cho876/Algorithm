#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define NIL -1

using namespace std;

bool DFS(vector<int>* v_adj, int index, bool*& isVisited_L, int*& match_L, int*& match_R);
void findCover(vector<int>* v_adj, int index, bool** map, bool*& isVisited_L, bool*& isVisited_R, int*& match_L, int*& match_R);

bool flag = false;
vector<int> v_ans_L;
vector<int> v_ans_R;

int main()
{
	int total_L, total_R;
	scanf("%d%d", &total_L, &total_R);
	vector<int>* v_adj = new vector<int>[total_L];

	int total_edge, edge_value;
	for (int i = 0; i < total_L; i++) {
		scanf("%d", &total_edge);
		for (int j = 0; j < total_edge; j++) {
			scanf("%d", &edge_value);
			v_adj[i].push_back(edge_value - 1);
		}
	}

	bool* isVisited_L = new bool[total_L];
	bool* isVisited_R = new bool[total_R];

	int* match_L = new int[total_L];
	int* match_R = new int[total_R];

	fill(match_L, match_L + total_L, NIL);
	fill(match_R, match_R + total_R, NIL);

	int count = 0;
	for (int i = 0; i < total_L; i++) {
		fill(isVisited_L, isVisited_L + total_L, false);
		if (DFS(v_adj, i, isVisited_L, match_L, match_R))
			count++;
	}

	//printf("Maximum matching: %d\n", count);

	bool** map = new bool*[total_L];
	for (int i = 0; i < total_L; i++)
		map[i] = new bool[total_R];

	for (int i = 0; i < total_L; i++)
		fill(map[i], map[i] + total_R, false);

	for (int i = 0; i < total_L; i++) {
		if (match_L[i] != NIL)
			map[i][match_L[i]] = true;
	}

	/*	for (int i = 0; i < total_L; i++) {
			for (int j = 0; j < total_R; j++)
				printf("%d ", map[i][j]);
			printf("\n");
		}
	*/
	fill(isVisited_L, isVisited_L + total_L, false);
	fill(isVisited_R, isVisited_R + total_R, false);

	for (int i = 0; i < total_L; i++) {
		if (match_L[i] == NIL && !isVisited_L[i])
			findCover(v_adj, i, map, isVisited_L, isVisited_R, match_L, match_R);
	}

	for (int i = 0; i < total_L; i++) {
		if (!isVisited_L[i]) {
			v_ans_L.push_back(i);
		}
	}

	printf("%d\n", v_ans_L.size() + v_ans_R.size());

	printf("%d ", v_ans_L.size());
	for (int i = 0; i < v_ans_L.size(); i++)
		printf("%d ", v_ans_L[i] + 1);
	printf("\n");

	printf("%d ", v_ans_R.size());
	for (int i = 0; i < v_ans_R.size(); i++)
		printf("%d ", v_ans_R[i] + 1);
	printf("\n");

	return 0;
}

void findCover(vector<int>* v_adj, int index, bool** map, bool*& isVisited_L, bool*& isVisited_R, int*& match_L, int*& match_R) {
	if (!flag) {  // L to R
		isVisited_L[index] = true;

		int next_R;
		for (int i = 0; i < v_adj[index].size(); i++) {
			next_R = v_adj[index][i];
			if (!map[index][next_R] && !isVisited_R[next_R]) {
				flag = true;
				findCover(v_adj, next_R, map, isVisited_L, isVisited_R, match_L, match_R);
			}
		}
	}
	else if (flag) {  // R to L
		isVisited_R[index] = true;
		v_ans_R.push_back(index);
		if (match_R[index] != NIL && !isVisited_L[match_R[index]]) {
			flag = false;
			findCover(v_adj, match_R[index], map, isVisited_L, isVisited_R, match_L, match_R);
		}
	}
}

bool DFS(vector<int>* v_adj, int index, bool*& isVisited_L, int*& match_L, int*& match_R) {
	if (!isVisited_L[index]) {
		isVisited_L[index] = true;

		int next_R;
		for (int i = 0; i < v_adj[index].size(); i++) {
			next_R = v_adj[index][i];

			if (match_R[next_R] == NIL || DFS(v_adj, match_R[next_R], isVisited_L, match_L, match_R)) {
				match_L[index] = next_R;
				match_R[next_R] = index;
				return true;
			}
		}
	}
	return false;
}