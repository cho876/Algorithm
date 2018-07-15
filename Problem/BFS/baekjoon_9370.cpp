#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define INF 987654321

using namespace std;

vector<int> dist;
vector<int> dstList;

vector<int> Dijkstra(vector<pair<int,int> >* v_adj, int nodes, int src) {
	dist.resize(nodes);
	fill(dist.begin(), dist.end(), INF);
	dist[src] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >path;
	path.push({ 0, src });

	int curNode, curWeight, nextNode, nextWeight;
	while (!path.empty()) {
		curWeight = path.top().first;
		curNode = path.top().second;
		path.pop();

		if (dist[curNode] < curWeight)
			continue;

		for (int i = 0; i < v_adj[curNode].size(); i++) {
			nextNode = v_adj[curNode][i].first;
			nextWeight = curWeight + v_adj[curNode][i].second;

			if (dist[nextNode] > nextWeight) {
				dist[nextNode] = nextWeight;
				path.push({ nextWeight, nextNode });
			}
		}
	}
	return dist;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		int nodes, edges, candidates;
		scanf("%d%d%d", &nodes, &edges, &candidates);

		int src, sect1, sect2;
		scanf("%d%d%d", &src, &sect1, &sect2);
		src--; sect1--; sect2--;

		vector<pair<int, int> >* v_adj = new vector<pair<int, int> >[nodes];

		int from, to, weight;
		for (int i = 0; i < edges; i++) {
			scanf("%d%d%d", &from, &to, &weight);
			from--; to--;
			v_adj[from].push_back({ to, weight });
			v_adj[to].push_back({ from, weight });
		}

		dstList.clear();

		int dst;
		for (int i = 0; i < candidates; i++) {
			scanf("%d", &dst);
			dst--;
			dstList.push_back(dst);
		}

		sort(dstList.begin(), dstList.end());
		vector<int> dist1 = Dijkstra(v_adj, nodes, src);

		int start = dist1[sect1] < dist1[sect2] ? sect2 : sect1;
		vector<int> dist2 = Dijkstra(v_adj, nodes, start);

		for (int i = 0; i < dstList.size(); i++) {
			int here = dstList[i];

			if (dist1[here] == INF || dist2[here] == INF)
				continue;

			if (dist1[here] == (dist1[start] + dist2[here]))
				printf("%d ", here+1);
		}
		puts("");
	}
	return 0;
}