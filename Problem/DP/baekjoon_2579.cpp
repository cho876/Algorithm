#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int level;
	scanf("%d", &level);
	vector<int> v_level;

	vector<int> v_total(level);

	int tmp;
	for (int i = 0; i < level; i++) {
		scanf("%d", &tmp);
		v_level.push_back(tmp);
	}

	v_total[0] = v_level[0];
	v_total[1] = v_level[0] + v_level[1];
	v_total[2] = max(v_level[0], v_level[1]) + v_level[2];

	int maxValue;
	for (int i = 3; i < level; i++) {
		maxValue = max(v_level[i - 1] + v_total[i - 3], v_total[i-2]);
		v_total[i] = maxValue + v_level[i];
	}
	printf("%d", v_total[level - 1]);
	return 0;
}