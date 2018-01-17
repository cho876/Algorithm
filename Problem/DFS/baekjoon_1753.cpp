#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

#define INF 999999

using namespace std;

void Dijkstra(vector<pair<int, int> >* v_pair, int src, int size);

int main()
{
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<pair<int, int> >* v_pair = new vector<pair<int, int> >[nodes];

	int src;
	scanf("%d", &src);

	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &from, &to, &weight);
		v_pair[from - 1].push_back(make_pair(to - 1, weight));
	}


	Dijkstra(v_pair, src - 1, nodes);

	return 0;
}

void Dijkstra(vector<pair<int, int> >* v_pair, int src, int size) {
	vector<int> v_dist;
	v_dist.resize(size);

	for (int i = 0; i < size; i++)
		v_dist[i] = INF;
	v_dist[src] = 0;

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

			if (v_dist[nextNode] > nextDist) {
				v_dist[nextNode] = nextDist;
				q_list.push(make_pair(nextNode, nextDist));
			}
		}
	}

	for (int i = 0; i < v_dist.size(); i++) {
		if (v_dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", v_dist[i]);
	}
}