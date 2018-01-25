#include <iostream>	
#include <cstdio>
#include <vector>
#include <queue>

#define INF 99999999

using namespace std;

void Dijkstra(vector<pair<int, int> >* v_origin, int size, int src);
int rev_Dijkstra(vector<pair<int, int> >* v_origin, int size, int src, int dst);

vector<int> dist;
int main()
{
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<pair<int, int> >* v_origin = new vector<pair<int, int> >[nodes + 1];

	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &from, &to, &weight);

		v_origin[from].push_back(make_pair(to, weight));
		v_origin[to].push_back(make_pair(from, weight));
	}

	for (int i = 1; i <= nodes; i++) {
		Dijkstra(v_origin, nodes, i);

		for (int j = 1; j < nodes + 1; j++) {
			if (i == j)
				printf("- ");
			else
				printf("%d ", rev_Dijkstra(v_origin, nodes, i, j));
		}
		printf("\n");
	}

}

void Dijkstra(vector<pair<int, int> >* v_origin, int size, int src) {
	dist.resize(size + 1);
	for (int i = 0; i < size + 1; i++)
		dist[i] = INF;
	dist[src] = 0;

	priority_queue<pair<int, int> >q_list;
	q_list.push(make_pair(src, 0));

	int curNode, curWeight;
	while (!q_list.empty()) {
		curNode = q_list.top().first;
		curWeight = q_list.top().second;
		q_list.pop();

		for (int i = 0; i < v_origin[curNode].size(); i++) {
			int nextNode = v_origin[curNode][i].first;
			int nextWeight = curWeight + v_origin[curNode][i].second;

			if (dist[nextNode] > nextWeight) {
				dist[nextNode] = nextWeight;
				q_list.push(make_pair(nextNode, nextWeight));
			}
		}
	}
}

int rev_Dijkstra(vector<pair<int, int> >* v_origin, int size, int src, int dst) {
	int count = 0;

	priority_queue<int> q_list;
	q_list.push(dst);

	int curNode, prevNode, prevWeight;
	while (!q_list.empty()) {
		curNode = q_list.top();
		q_list.pop();

		for (int i = 0; i < v_origin[curNode].size(); i++) {
			prevNode = v_origin[curNode][i].first;
			prevWeight = v_origin[curNode][i].second;

			if (dist[curNode] == dist[prevNode] + prevWeight) {
				if (v_origin[curNode][i].first == src)
					return curNode;

				q_list.push(prevNode);
			}
		}
	}
	return 0;
}