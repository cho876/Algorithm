#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

#define INF 99999999

using namespace std;


int Dijkstra(vector<pair<int, int> >* v_adj, bool*& isVisited, int nodes, int src, int dst) {
	vector<int> dist;
	dist.resize(nodes);

	fill(dist.begin(), dist.end(), INF);
	dist[src] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > path;
	path.push(make_pair(0, src));

	int curNode, curWeight, nextNode, nextWeight;
	while (!path.empty()) {
		curWeight = path.top().first;
		curNode = path.top().second;
		path.pop();

		if (curNode == dst)
			return dist[dst];

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
}

int main() {
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);

	vector<pair<int, int>>* v_adj = new vector<pair<int, int> >[nodes];

	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		v_adj[from - 1].push_back(make_pair(to - 1, weight));
	}

	bool* isVisited = new bool[nodes];
	fill(isVisited, isVisited + nodes, false);

	int src, dst;
	scanf("%d%d", &src, &dst);

	printf("%d\n", Dijkstra(v_adj, isVisited, nodes, src - 1, dst - 1));

	return 0;
}