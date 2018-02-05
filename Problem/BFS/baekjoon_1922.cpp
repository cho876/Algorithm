#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

#define INF 999999999

using namespace std;

void BFS(vector<pair<int, int> >* v_adj, int src, int size, bool*& isVisited, int& result);

int main() {
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<pair<int, int> >* v_adj = new vector<pair<int, int> >[nodes];

	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		v_adj[from - 1].push_back(make_pair(weight, to - 1));
		v_adj[to - 1].push_back(make_pair(weight, from - 1));
	}

	bool* isVisited = new bool[nodes];
	for (int i = 0; i < nodes; i++)
		isVisited[i] = false;

	int result = 0;
	BFS(v_adj, 0, nodes, isVisited, result);

	printf("%d\n", result);

	return 0;
}

void BFS(vector<pair<int, int> >* v_adj, int src, int size, bool*& isVisited, int& result) {
	vector<int> dist;
	dist.resize(size);

	for (int i = 0; i < size; i++)
		dist[i] = INF;
	dist[src] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > path;
	path.push(make_pair(0, src));

	int curNode, curWeight, nextNode, nextWeight;
	while (!path.empty()) {
		curNode = path.top().second;
		curWeight = path.top().first;
		path.pop();

		if (isVisited[curNode])
			continue;
		isVisited[curNode] = true;
		result += dist[curNode];

		for (int i = 0; i < v_adj[curNode].size(); i++) {
			nextNode = v_adj[curNode][i].second;
			nextWeight = v_adj[curNode][i].first;

			if (isVisited[nextNode])
				continue;

			if (dist[nextNode] > nextWeight) {
				dist[nextNode] = nextWeight;
				path.push(make_pair(nextWeight, nextNode));
			}
		}
	}
}