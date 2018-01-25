#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 999999999

using namespace std;

void Dijkstra(vector<int>* v_list, int size, int src);

vector<int> dist;

int main()
{
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<int>* v_list = new vector<int>[nodes];


	int from, to;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d", &from, &to);
		v_list[from - 1].push_back(to - 1);
		v_list[to - 1].push_back(from - 1);
	}
	Dijkstra(v_list, nodes, 0);
	

	int result = dist[0];
	int result_index = 0;
	for (int i = 1; i < nodes; i++) {
		if (dist[i] > result) {
			result = dist[i];
			result_index = i;
		}
	}

	int same = 0;
	for (int i = 0; i < nodes; i++) {
		if (result == dist[i])
			same++;
	}

	printf("%d %d %d \n", result_index+1, dist[result_index], same);

	return 0;
}

void Dijkstra(vector<int>* v_list, int size, int src) {
	dist.resize(size);
	for (int i = 0; i < size; i++)
		dist[i] = INF;
	dist[src] = 0;

	priority_queue<int> q_list;
	q_list.push(src);

	int curNode, nextNode;
	while (!q_list.empty()) {
		curNode = q_list.top();
		q_list.pop();

		for (int i = 0; i < v_list[curNode].size(); i++) {
			nextNode = v_list[curNode][i];

			if (dist[nextNode] > 1 + dist[curNode]) {
				dist[nextNode] = 1 + dist[curNode];
				q_list.push(nextNode);
			}
		}
	}
}