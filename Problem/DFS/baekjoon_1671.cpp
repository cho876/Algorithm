#include <iostream>
#include <cstdio>
#include <vector>

#define NIL  -1

using namespace std;

struct Shark {
public:
	int size;
	int speed;
	int intel;

	Shark(int size, int speed, int intel) : size(size), speed(speed), intel(intel) {};
};


bool DFS(vector<int>* v_adj, int src, bool*& isMatched, int*& matched_R);
void makeEdge(vector<Shark> shark_info, int size, vector<int>*& v_adj);

int main() {
	int nodes;
	scanf("%d", &nodes);
	vector<int>* v_adj = new vector<int>[nodes];
	vector<Shark> shark_info;

	int size, speed, intel;
	for (int i = 0; i < nodes; i++) {
		scanf("%d%d%d", &size, &speed, &intel);
		shark_info.push_back(Shark(size, speed, intel));
	}
	makeEdge(shark_info, nodes, v_adj);

/*	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < v_adj[i].size(); j++) {
			printf("%d ", v_adj[i][j]);
		}
		printf("\n");
	}
	*/
	bool* isMatched = new bool[nodes];
	int* matched_R = new int[nodes];

	fill(matched_R, matched_R + nodes, NIL);

	int count = 0;
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < 2; j++) {
			fill(isMatched, isMatched + nodes, false);
			DFS(v_adj, i, isMatched, matched_R);
		}
	}

	for (int i = 0; i < nodes; i++) {
		if (matched_R[i] == NIL)
			count++;
	}

	printf("%d\n", count);
}

bool DFS(vector<int>* v_adj, int src, bool*& isMatched, int*& matched_R) {
	if (!isMatched[src]) {
		isMatched[src] = true;

		int next_R;
		for (int i = 0; i < v_adj[src].size(); i++) {
			next_R = v_adj[src][i];
			if (matched_R[next_R] == NIL || DFS(v_adj, matched_R[next_R], isMatched, matched_R)) {
				matched_R[next_R] = src;
				return true;
			}
		}
	}
	return false;
}

void makeEdge(vector<Shark> shark_info, int size, vector<int>*& v_adj) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if (i == j)
				continue;

			if (shark_info[i].size >= shark_info[j].size && shark_info[i].speed >= shark_info[j].speed && shark_info[i].intel >= shark_info[j].intel)
				v_adj[i].push_back(j);

			else if (shark_info[i].size <= shark_info[j].size && shark_info[i].speed <= shark_info[j].speed && shark_info[i].intel <= shark_info[j].intel)
				v_adj[j].push_back(i);
		}
	}
}