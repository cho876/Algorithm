#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int res = 1;
int cnt;
int minusCnt;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> vec;

	int weight;
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight);
		vec.push_back(weight);
	}
	sort(vec.begin(), vec.end(), greater<int>());


	int t1 = vec[0] * vec[1];
	int t2 = vec[n - 1] * vec[n - 2];

	int t3 = vec[0] * vec[1] * vec[2];
	int t4 = vec[n - 1] * vec[n - 2] * vec[n - 3];
	int t5 = vec[0] * vec[1] * vec[n-1];
	int t6 = vec[n - 1] * vec[n - 2] * vec[0];

	int res = max({ t1, t2, t3, t4 });

	printf("%d\n", res);
	return 0;
}