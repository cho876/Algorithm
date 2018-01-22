#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int test;
	scanf("%d", &test);

	for (int i = 0; i < test; i++) {
		int height;
		scanf("%d", &height);

		vector<int> v_height;
		v_height.resize(height);

		int values;
		for (int i = 0; i < height; i++) {
			scanf("%d", &values);
			v_height[i] = values;
		}

		sort(v_height.begin(), v_height.end(), less<int>());

		vector<int> v_result;
		v_result.resize(height);

		int j = 0;
		for (int i = 0; i < height / 2; i++) {
			v_result[i] = v_height[j];
			v_result[height - 1 - i] = v_height[j + 1];
			j += 2;
		}

		if (height % 2 != 0)
			v_result[height / 2] = v_height[height - 1];

		int result = 0;
		for (int i = 1; i < v_result.size(); i++) {
			result = max(result, abs(v_result[i] - v_result[i - 1]));
		}

		result = max(result, abs(v_result[0] - v_result[height - 1]));
		printf("%d\n", result);
	}
}