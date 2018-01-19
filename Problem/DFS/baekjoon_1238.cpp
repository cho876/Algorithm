#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define INF 9999999999

using namespace std;

int Dijkstra(vector<pair<int, int> >* v_pair, int src, int dst, int size);

int main()
{
	int nodes, edges, dst;
	scanf("%d%d%d", &nodes, &edges, &dst);
	vector<pair<int, int> >* v_pair = new vector<pair<int, int> >[nodes];

	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		v_pair[from - 1].push_back(make_pair(to - 1, weight));
	}

	int result = 0;
	int eachDist = 0;

	for (int i = 0; i < nodes; i++) {
		eachDist = Dijkstra(v_pair, i, dst - 1, nodes) + Dijkstra(v_pair, dst - 1, i, nodes);
		result = max(eachDist, result);
	}
	printf("%d\n", result);

	return 0;
}

int Dijkstra(vector<pair<int, int> >* v_pair, int src, int dst, int size) {
	vector<int> dist;
	dist.resize(size);
	for (int i = 0; i < size; i++)
		dist[i] = INF;
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