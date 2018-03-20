#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <functional>

using namespace std;

int main() {
	int num;
	scanf("%d", &num);

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > path;
	path.push(make_pair(0, num));

	int tmp_num, local, cnt;
	while (!path.empty()) {
		cnt = path.top().first;
		tmp_num = path.top().second;
		local = tmp_num;
		path.pop();

		if (tmp_num == 1) {
			printf("%d\n", cnt);
			break;
		}

		if (tmp_num % 3 == 0)
			path.push(make_pair(cnt + 1, tmp_num / 3));
		if (tmp_num % 2 == 0)
			path.push(make_pair(cnt + 1, tmp_num / 2));
		if (tmp_num != 1)
			path.push(make_pair(cnt + 1, tmp_num - 1));
	}
	return 0;
}