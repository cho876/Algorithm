#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define INF 987654321

using namespace std;

int getDist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	int n, m, c1, c2;
	scanf("%d%d%d%d", &n, &m, &c1, &c2);

	vector<pair<int, int> > vec;
	int value;
	for (int i = 0; i < n; i++) {
		scanf("%d", &value);
		vec.push_back({ value, 0 });
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &value);
		vec.push_back({ value, 1 });
	}
	sort(vec.begin(), vec.end());

	int curDist = 0;
	int resDist = INF;
	int curCnt = 0;

	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i].second != vec[i + 1].second) {
			curDist = getDist(vec[i].first, c1, vec[i + 1].first, c2);
			if (resDist > curDist) {
				resDist = curDist;
				curCnt = 1;
			}
			else if (resDist == curDist)
				curCnt++;
		}
	}
	printf("%d %d\n", resDist, curCnt);
}