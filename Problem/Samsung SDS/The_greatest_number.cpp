#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int resCnt;
int resValue;

int main() {
	int n;
	scanf("%d", &n);

	int value;
	vector<int> v_adj;
	for (int i = 0; i < n; i++) {
		scanf("%d", &value);
		v_adj.push_back(value);
	}
	sort(v_adj.begin(), v_adj.end());

	int cnt = 1;
	for (int i = 0; i < n - 1; i++) {
		if (v_adj[i] == v_adj[i + 1]) {
			cnt++;
			if (cnt > resCnt) {
				resCnt = cnt;
				resValue = v_adj[i];
			}
		}
		else
			cnt = 1;
	}

	printf("%d\n", resValue);
	return 0;
}