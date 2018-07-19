#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cnt;
vector<int> map;

bool isPossible(int level) {
	for (int i = 0; i < level; i++) {
		if (map[level] == map[i] || abs(map[level] - map[i]) == abs(level - i))
			return false;
	}
	return true;
}

void DFS(int level) {
	if (level == n) {
		cnt++;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			map[level] = i;
			if (isPossible(level))
				DFS(level + 1);
		}
	}
}

int main() {
	scanf("%d", &n);

	map.resize(n);
	DFS(0);

	printf("%d\n", cnt);
	return 0;
}