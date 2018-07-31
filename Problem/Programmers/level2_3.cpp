#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void solution(vector<vector<int> > vec) {
	for (int i = 1; i < vec.size(); i++) {
		vec[i][0] += max(vec[i - 1][1], max(vec[i - 1][2], vec[i - 1][3]));
		vec[i][1] += max(vec[i - 1][0], max(vec[i - 1][2], vec[i - 1][3]));
		vec[i][2] += max(vec[i - 1][0], max(vec[i - 1][1], vec[i - 1][3]));
		vec[i][3] += max(vec[i - 1][0], max(vec[i - 1][1], vec[i - 1][2]));
	}

	int res = 0;
	int lng = vec.size() - 1;
	for (int i = 0; i < vec[lng].size(); i++)
		res = max(res, vec[lng][i]);

	printf("%d\n", res);
}