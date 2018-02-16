#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>

#define NIL -1

using namespace std;

double getDist(pair<double, double> v_mouse, pair<double, double> v_house);
bool DFS(vector<int>* v_adj, int src, bool*& isVisited, int*& matched_R);

int main() {
	int mouse, house, bird, speed;
	scanf("%d%d%d%d", &mouse, &house, &bird, &speed);
	vector<pair<double, double> > v_mouse;
	vector<pair<double, double> > v_house;

	double dx, dy;
	for (int i = 0; i < mouse; i++) {
		scanf("%lf%lf", &dx, &dy);
		v_mouse.push_back(make_pair(dx, dy));
	}

	for (int i = 0; i < house; i++) {
		scanf("%lf%lf", &dx, &dy);
		v_house.push_back(make_pair(dx, dy));
	}
	
	vector<int>* v_adj = new vector<int>[mouse];

	double dist;
	for (int i = 0; i < mouse; i++) {
		for (int j = 0; j < house; j++) {
			dist = getDist(v_mouse[i], v_house[j]);
			if ((double)bird*speed >= dist) {
				v_adj[i].push_back(j);
			}
		}
	}

	bool* isVisited = new bool[mouse];
	int* matched_R = new int[house];

	fill(matched_R, matched_R + house, NIL);

	int count = 0;
	for (int i = 0; i < mouse; i++) {
		fill(isVisited, isVisited + mouse, false);
		if (DFS(v_adj, i, isVisited, matched_R))
			count++;
	}

	printf("%d\n", mouse-count);
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

double getDist(pair<double, double> v_mouse, pair<double, double> v_house) {
	double dist = sqrt(pow(v_mouse.first - v_house.first, 2) + pow(v_mouse.second - v_house.second, 2));
	return dist;
}