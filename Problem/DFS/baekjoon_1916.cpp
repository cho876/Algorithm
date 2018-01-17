#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define INF 9999999999

using namespace std;

void Dijkstra(vector<pair<int, int> >* v_pair, int src, int dst, int size);

int main()
{
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);

	vector<pair<int, int> >* v_pair = new vector<pair<int, int> >[nodes];

	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		v_pair[from - 1].push_back(make_pair(to - 1, weight));
	}

	int src, dst;
	scanf("%d%d", &src, &dst);

	Dijkstra(v_pair, src - 1, dst - 1, nodes);

	return 0;
}

void Dijkstra(vector<pair<int, int> >* v_pair, int src, int dst, int size) {
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

	printf("%d\n", dist[dst]);
}