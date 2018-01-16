#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 99999999

using namespace std;

void Dijkstra(vector<pair<int, int> >* v_list, int src, int size, vector<int>& v_result);

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;

	int src;
	cin >> src;
	
	vector<pair<int, int> >* v_list = new vector<pair<int, int> >[nodes];
	
	int from, to, weight;
	for (int i = 0; i < edges; i++) {
		cin >> from >> to >> weight;
		v_list[from - 1].push_back(make_pair(to - 1, weight));
	}

	vector<int> v_result;
	Dijkstra(v_list, src-1, nodes, v_result);

	for (int i = 0; i < v_result.size(); i++) {
		if (v_result[i] == INF)
			cout << "INF" << endl;
		else
			cout << v_result[i] << endl;
	}

	return 0;
}

void Dijkstra(vector<pair<int, int> >* v_list, int src, int size, vector<int>& v_result) {
	vector<int> v_dist;
	for (int i = 0; i < size; i++)
		v_dist.push_back(INF);

	v_dist[src] = 0;

	priority_queue < pair<int,int>, vector<pair<int, int> >, less<pair<int, int> > > q_list;
	q_list.push(make_pair(src, 0));

	int curSrc, curDist;
	while (!q_list.empty()) {
		curSrc = q_list.top().first;
		curDist = q_list.top().second;
		q_list.pop();

		if (v_dist[curSrc] < curDist)
			continue;

		int nextSrc, nextDist;
		for (int i = 0; i < v_list[curSrc].size(); i++) {
			nextSrc = v_list[curSrc][i].first;
			nextDist = curDist + v_list[curSrc][i].second;

			if (v_dist[nextSrc] > nextDist) {
				v_dist[nextSrc] = nextDist;
				q_list.push(make_pair(nextSrc, nextDist));
			}
		}
	}

	v_result = v_dist;
}