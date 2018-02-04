#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

#define INF 99999999

using namespace std;

void Dijkstra(vector<pair<int, int> >* v_adj, bool*& isVisited, int size, int src);


int main() {
	int nodes, edges, src;
	scanf("%d%d%d", &nodes, &edges, &src);
	vector<pair<int, int> >* v_adj = new vector<pair<int, int> >[nodes];

	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		v_adj[from - 1].push_back(make_pair(to - 1, weight));
	}

	bool* isVisited = new bool[nodes];
	for (int i = 0; i < nodes; i++)
		isVisited[i] = false;

	Dijkstra(v_adj, isVisited, nodes, src-1);

	return 0;
}

void Dijkstra(vector<pair<int, int> >* v_adj, bool*& isVisited, int size, int src) {
	vector<int> dist;
	dist.resize(size);

	for (int i = 0; i < size; i++)
		dist[i] = INF;

	dist[src] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > path;
	path.push(make_pair(0, src));

	int curNode, curWeight, nextNode, nextWeight;
	while (!path.empty()) {
		curWeight = path.top().first;
		curNode = path.top().second;
		path.pop();

		// cout << curNode << ", " << curWeight << endl;

		isVisited[curNode] = true;

		for (int i = 0; i < v_adj[curNode].size(); i++) {
			nextNode = v_adj[curNode][i].first;
			nextWeight = curWeight + v_adj[curNode][i].second;

			if (isVisited[nextNode])
				continue;

			if (dist[nextNode] > nextWeight) {
				dist[nextNode] = nextWeight;
				path.push(make_pair(nextWeight, nextNode));
			}
		}
	}

	for (int i = 0; i < size; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return;
}