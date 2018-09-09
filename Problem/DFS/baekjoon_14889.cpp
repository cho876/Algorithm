#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

#define MAX 21
#define INF 987654321

using namespace std;

int N;
int map[MAX][MAX];
int ans = INF;

vector<int> v_left;
vector<int> v_right;

int dfs(int idx) {
	if (idx == N) {
		if (v_left.size() == v_right.size()) {
			int left_sum = 0;
			int right_sum = 0;

			for (int i = 0; i < v_left.size(); i++) {
				for (int j = i + 1; j < v_left.size(); j++) {
					left_sum += (map[v_left[i]][v_left[j]] + map[v_left[j]][v_left[i]]);
					right_sum += (map[v_right[i]][v_right[j]] + map[v_right[j]][v_right[i]]);
				}
			}
			ans = min(ans, abs(left_sum - right_sum));
		}
		return 0;
	}

	v_left.push_back(idx);
	dfs(idx + 1);
	v_left.pop_back();

	v_right.push_back(idx);
	dfs(idx + 1);
	v_right.pop_back();

	return 0;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	}

	dfs(0);
	printf("%d\n", ans);

	return 0;
}