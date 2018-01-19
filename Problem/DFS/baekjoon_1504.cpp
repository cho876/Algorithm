#include <iostream>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int Dijstra(vector<pair<int, int> >* v_pair, int src, int dst, int size);

int main()
{
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<pair<int, int> >* v_pair = new vector<pair<int, int> >[nodes];

	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		v_pair[from - 1].push_back(make_pair(to - 1, weight));
		v_pair[to - 1].push_back(make_pair(from - 1, weight));
	}

	int node1, node2;
	scanf("%d%d", &node1, &node2);

	int	result1 = INT_MAX;
	int result2 = INT_MAX;

	if (Dijstra(v_pair, 0, node1 - 1, nodes) != INT_MAX && Dijstra(v_pair, node1 - 1, node2 - 1, nodes) != INT_MAX && Dijstra(v_pair, node2 - 1, nodes - 1, nodes) != INT_MAX)
		result1 = Dijstra(v_pair, 0, node1 - 1, nodes) + Dijstra(v_pair, node1 - 1, node2 - 1, nodes) + Dijstra(v_pair, node2 - 1, nodes - 1, nodes);

	if (Dijstra(v_pair, 0, node2 - 1, nodes) != INT_MAX && Dijstra(v_pair, node2 - 1, node1 - 1, nodes) != INT_MAX && Dijstra(v_pair, node1 - 1, nodes - 1, nodes) != INT_MAX)
		result2 = Dijstra(v_pair, 0, node2 - 1, nodes) + Dijstra(v_pair, node2 - 1, node1 - 1, nodes) + Dijstra(v_pair, node1 - 1, nodes - 1, nodes);


	if (result1 == INT_MAX && result2 == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", min(result1, result2));

	return 0;
}

int Dijstra(vector<pair<int, int> >* v_pair, int src, int dst, int size) {
	vector<int> dist;
	dist.resize(size);

	for (int i = 0; i < size; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	queue<pair<int, int> > q_list;
	q_list.push(make_pair(src, 0));

	int curNode, curDist;
	while (!q_list.empty()) {
		curNode = q_list.front().first;
		curDist = q_list.front().second;
		q_list.pop();

		int nextNode, nextDist;
		for (int i = 0; i < v_pair[curNode].size(); i++) {
			nextNode = v_pair[curNode][i].first;
			nextDist = curDist + v_pair[curNode][i].second;

			if (dist[nextNode] > nextDist) {
				dist[nextNode] = nextDist;
				q_list.push(make_pair(nextNode, nextDist));
			}
		}
	}
	return dist[dst];
}