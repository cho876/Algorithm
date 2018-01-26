#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int DFS(vector<pair<int, int> >& v_supply, vector<pair<int, int> >* v_list, int index, bool*& isVisited, int*& parent);

int main()
{
	int nodes;
	scanf("%d", &nodes);

	vector<pair<int, int> > v_supply;

	int type, supply;
	for (int i = 0; i < nodes; i++) {
		scanf("%d%d", &type, &supply);
		v_supply.push_back(make_pair(type, supply));
	}

	vector<pair<int, int> >* v_list = new vector<pair<int, int> >[nodes];

	int from, to, weight;
	for (int i = 0; i < nodes - 1; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		v_list[from - 1].push_back(make_pair(to - 1, weight));
		v_list[to - 1].push_back(make_pair(from - 1, weight));
	}

	bool* isVisited = new bool[nodes];
	int* parent = new int[nodes];

	for (int i = 0; i < nodes; i++) {
		isVisited[i] = false;
		parent[i] = -1;
	}
	printf("%d\n", DFS(v_supply, v_list, 0, isVisited, parent));

	return 0;
}

int DFS(vector<pair<int, int> >& v_supply, vector<pair<int, int> >* v_list, int index, bool*& isVisited, int*& parent) {
	int curNode = index;
	int c_prime = 0;
	isVisited[curNode] = true;

	int nextNode, nextWeight;
	for (int i = 0; i < v_list[curNode].size(); i++) {
		nextNode = v_list[curNode][i].first;
		nextWeight = v_list[curNode][i].second;

		if (!isVisited[nextNode]) {
			parent[nextNode] = curNode;
			if (!DFS(v_supply, v_list, nextNode, isVisited, parent))
				return 0;

			if (v_supply[curNode].first == 1) {
				// Case 1) Demand & Demand
				if (v_supply[nextNode].first == 1) {
					if (v_supply[nextNode].second > nextWeight)
						return 0;

					v_supply[curNode].second += min(v_supply[nextNode].second, nextWeight);
				}

				// Case 2)  Demand & Supply
				else if (v_supply[nextNode].first == 0) {
					if (v_supply[curNode].second <= min(v_supply[nextNode].second, nextWeight))
						c_prime = max(min(v_supply[nextNode].second, nextWeight), c_prime);
				}
			}
			else if (v_supply[curNode].first == 0) {
				// Case 3) Supply & Demand
				if (v_supply[nextNode].first == 1) {
					if (v_supply[curNode].second >= min(v_supply[nextNode].second, nextWeight))
						v_supply[curNode].second -= min(v_supply[nextNode].second, nextWeight);
				}
			}
		}
	}if (c_prime >= v_supply[curNode].second) {
		v_supply[curNode].second = c_prime - v_supply[curNode].second;
		v_supply[curNode].first = 0;
	}
	else if (parent[curNode] == -1 && v_supply[curNode].first == 1)
		return 0;
	return 1;
}