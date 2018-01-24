#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 999999999

using namespace std;

void Dijkstra(vector<pair<int, int> >* v_list, int size, int src);
void printResult(vector<int> dist);

int main()
{
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		int nodes, edges, src;
		scanf("%d%d%d", &nodes, &edges, &src);

		vector<pair<int, int> >* v_list = new vector<pair<int, int> >[nodes];

		int from, to, weight;
		for (int i = 0; i < edges; i++) {
			scanf("%d%d%d", &to, &from, &weight);
			v_list[from - 1].push_back(make_pair(to - 1, weight));
		}

		Dijkstra(v_list, nodes, src - 1);
	}

	return 0;
}

void Dijkstra(vector<pair<int, int> >* v_list, int size, int src) {
	vector<int> dist;
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
	printResult(dist);
}

void printResult(vector<int> dist) {
	int counter = 0;
	int time = 0;

	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] != INF) {
			counter++;
			time = max(time, dist[i]);
		}
	}

	printf("%d %d\n", counter, time);
}