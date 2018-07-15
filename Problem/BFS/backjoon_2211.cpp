#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

#define INF 987654321

using namespace std;

vector<int> dist;
vector<pair<int, int> >  res;

void Dijkstra(vector<pair<int, int> >* v_adj, int nodes, int src) {
	dist.resize(nodes);
	fill(dist.begin(), dist.end(), INF);
	dist[0] = 0;

	priority_queue < pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > path;
	path.push({ 0,{0, 0} });

	int curNode, curParent, curWeight, nextNode, nextParent, nextWeight;
	while (!path.empty()) {
		curWeight = path.top().first;
		curNode = path.top().second.first;
		curParent = path.top().second.second;
		path.pop();

		if (dist[curNode] < curWeight)
			continue;

		res.push_back({ curNode + 1, curParent + 1 });

		for (int i = 0; i < v_adj[curNode].size(); i++) {
			nextWeight = curWeight + v_adj[curNode][i].second;
			nextNode = v_adj[curNode][i].first;
			nextParent = curNode;

			if (dist[nextNode] > nextWeight) {
				dist[nextNode] = nextWeight;
				path.push({ nextWeight, {nextNode, nextParent} }); 
			}
		}
	}
	return;
}

int main() {
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	
	vector<pair<int, int> >* v_adj = new vector<pair<int, int> >[nodes];

	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		from--; to--;
		v_adj[from].push_back({ to, weight });
		v_adj[to].push_back({ from, weight });
	}
	
	Dijkstra(v_adj, nodes, 0);

	printf("%d\n", res.size()-1);
	for (int i = 1; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);

	return 0;
}