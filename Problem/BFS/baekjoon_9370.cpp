#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 99999999
using namespace std;

int Dijkstra(vector<pair<int, int> >* v_list, int size, int src, int dst);

vector<int> dist;

int main() {
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		int nodes, edges, candidates;
		scanf("%d%d%d", &nodes, &edges, &candidates);
		vector<pair<int, int> >* v_list = new vector<pair<int, int> >[nodes];

		int src, already1, already2;
		scanf("%d%d%d", &src, &already1, &already2);

		int from, to, weight, already_weight;
		for (int i = 0; i < edges; i++) {
			scanf("%d%d%d", &from, &to, &weight);

			if ((from == already1 && to == already2) || (from == already2 && to == already1))
				already_weight = weight;
			else {
				v_list[from-1].push_back(make_pair(to-1, weight));
				v_list[to-1].push_back(make_pair(from-1, weight));
			}
		}

		vector<int> v_result;
		
		int route1 = Dijkstra(v_list, nodes, src - 1, already1 - 1) + already_weight;		
		int route2 = Dijkstra(v_list, nodes, src - 1, already2 - 1) + already_weight;

		
		int cand = 0;
		int base = 0;
		int result = 0;
		for (int i = 0; i < candidates; i++) {
			scanf("%d", &cand);
			base = Dijkstra(v_list, nodes, src - 1, cand-1);
			result = min(route1 + Dijkstra(v_list, nodes, already2 - 1, cand - 1), route2 + Dijkstra(v_list, nodes, already1 - 1, cand - 1));
			
			if(base >= result)
				v_result.push_back(cand);
		}

		sort(v_result.begin(), v_result.end());

		for (int i = 0; i < v_result.size(); i++)
			printf("%d ", v_result[i]);
		printf("\n");
	}
	return 0;
}

int Dijkstra(vector<pair<int, int> >* v_list, int size, int src, int dst) {
	dist.resize(size);
	for (int i = 0; i < size; i++)
		dist[i] = INF;
	dist[src] = 0;

	priority_queue<pair<int, int> > q_list;
	q_list.push(make_pair(src, 0));

	int curNode, curWeight, nextNode, nextWeight;
	while (!q_list.empty()) {
		curNode = q_list.top().first;
		curWeight = q_list.top().second;
		q_list.pop();

		for (int i = 0; i < v_list[curNode].size(); i++) {
			nextNode = v_list[curNode][i].first;
			nextWeight = curWeight + v_list[curNode][i].second;

			if (dist[nextNode] > nextWeight) {
				dist[nextNode] = nextWeight;
				q_list.push(make_pair(nextNode, nextWeight));
			}
		}
	}
	return dist[dst];
}