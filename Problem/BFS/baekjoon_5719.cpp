#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

#define INF 99999999
#define MAX 500

using namespace std;

vector<int> dist;

void BFS(vector<pair<int, int> >* v_org, bool**& isVisited, int size, int src, int dst);
void r_BFS(vector<pair<int, int> >* v_rev, bool**& isVisited, int size, int src, int dst);

int main() {
	while (1) {
		int nodes, edges;
		scanf("%d%d", &nodes, &edges);

		if (nodes == 0 && edges == 0)
			break;

		int src, dst;
		scanf("%d%d", &src, &dst);

		vector<pair<int, int> >* v_org = new vector<pair<int, int> >[nodes];
		vector<pair<int, int> >* v_rev = new vector<pair<int, int> >[nodes];

		bool** isVisited = new bool*[nodes];
		for (int i = 0; i < nodes; i++)
			isVisited[i] = new bool[nodes];

		for (int i = 0; i < nodes; i++) {
			for (int j = 0; j < nodes; j++)
				isVisited[i][j] = false;
		}

		int from, to, weight;
		for (int i = 0; i < edges; i++) {
			scanf("%d%d%d", &from, &to, &weight);
			v_org[from].push_back(make_pair(to, weight));
			v_rev[to].push_back(make_pair(from, weight));
		}

		BFS(v_org, isVisited, nodes, src, dst);
		r_BFS(v_rev, isVisited, nodes, src, dst);
		BFS(v_org, isVisited, nodes, src, dst);

		if (dist[dst] == INF)
			printf("-1\n");
		else
			printf("%d\n", dist[dst]);
	}
	return 0;
}

void BFS(vector<pair<int, int> >* v_org, bool**& isVisited, int size, int src, int dst) {
	dist.resize(size);

	for (int i = 0; i < size; i++)
		dist[i] = INF;
	dist[src] = 0;

	priority_queue<pair<int, int> > q_list;
	q_list.push(make_pair(src, 0));

	int curNode, curDist, nextNode, nextDist;
	while (!q_list.empty()) {
		curNode = q_list.top().first;
		curDist = q_list.top().second;
		q_list.pop();

		for (int i = 0; i < v_org[curNode].size(); i++) {
			nextNode = v_org[curNode][i].first;
			nextDist = curDist + v_org[curNode][i].second;

			if (dist[nextNode] > nextDist && !isVisited[curNode][nextNode]) {
				dist[nextNode] = nextDist;
				q_list.push(make_pair(nextNode, nextDist));
			}
		}
	}
}

void r_BFS(vector<pair<int, int> >* v_rev, bool**& isVisited, int size, int src, int dst) {
	priority_queue<int> q_list;
	q_list.push(dst);

	int curNode, prevNode, prevDist;
	while (!q_list.empty()) {
		curNode = q_list.top();
		q_list.pop();

		for (int i = 0; i < v_rev[curNode].size(); i++) {
			prevNode = v_rev[curNode][i].first;
			prevDist = v_rev[curNode][i].second;

			if (dist[curNode] == dist[prevNode] + prevDist) {
				isVisited[prevNode][curNode] = true;
				q_list.push(prevNode);
			}
		}
	}
}