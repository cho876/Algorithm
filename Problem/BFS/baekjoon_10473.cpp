#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

#define INF 987654321

using namespace std;

vector<double> dist;

double distance(double curX, double curY, double nextX, double nextY) {
	return sqrt(pow(curX - nextX, 2) + pow(curY - nextY, 2));
}

void Dijkstra(vector<pair<double, int> >* v_adj, int nodes, int src) {
	dist.resize(nodes);
	fill(dist.begin(), dist.end(), INF);
	dist[0] = 0;

	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > path;
	path.push({ dist[0], 0 });

	int curNode, nextNode;
	double curWeight, nextWeight;

	while (!path.empty()) {
		curWeight = path.top().first;
		curNode = path.top().second;
		path.pop();

		if (dist[curNode] < curWeight)
			continue;

		for (int i = 0; i < v_adj[curNode].size(); i++) {
			nextWeight = curWeight + v_adj[curNode][i].first;
			nextNode = v_adj[curNode][i].second;

			if (dist[nextNode] > nextWeight) {
				dist[nextNode] = nextWeight;
				path.push({ nextWeight, nextNode });
			}
		}
	}
	printf("%.6lf\n", dist[1]);
}

int main() {
	double curX, curY, dstX, dstY;
	scanf("%lf%lf%lf%lf", &curX, &curY, &dstX, &dstY);

	vector<pair<double, double> > point;
	point.push_back({ curX, curY });
	point.push_back({ dstX, dstY });

	int cnt;
	scanf("%d", &cnt);

	double dx, dy;
	for (int i = 0; i < cnt; i++) {
		scanf("%lf%lf", &dx, &dy);
		point.push_back({ dx, dy });
	}

	vector<pair<double, int> >* v_adj = new vector<pair<double, int> >[cnt + 2];

	for (int i = 1; i < cnt + 2; i++) {
		v_adj[0].push_back({ distance(point[0].first, point[0].second, point[i].first, point[i].second) / 5.0, i });
		if (i == 1)
			continue;

		v_adj[i].push_back({ 2.0 + abs(distance(point[i].first, point[i].second, point[1].first, point[1].second) - 50) / 5.0, 1 });

		for (int j = i + 1; j < cnt + 2; j++) {
			double time = 2.0 + abs(distance(point[i].first, point[i].second, point[j].first, point[j].second) - 50) / 5.0;
			v_adj[i].push_back({ time, j });
			v_adj[j].push_back({ time, i });
		}
	}

	Dijkstra(v_adj, cnt + 2, 0);
	return 0;
}