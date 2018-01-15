#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

#define MAX 100000

using namespace std;

int main()
{
	int subin, sister;
	cin >> subin >> sister;

	bool isVisited[MAX] = { false };

	queue<pair<int, int>> q_src;
	q_src.push({ subin, 0 });

	while (!q_src.empty()) {
		int curSrc = q_src.front().first;
		int time = q_src.front().second;
		q_src.pop();

		if (curSrc < 0 || curSrc > 100000)
			continue;

		if (isVisited[curSrc])
			continue;

		if (curSrc == sister) {
			cout << time << endl;
			break;
		}
		isVisited[curSrc] = true;


		q_src.push({ curSrc * 2, time + 1 });
		q_src.push({ curSrc + 1, time + 1 });
		q_src.push({ curSrc - 1, time + 1 });
	}

	return 0;
}