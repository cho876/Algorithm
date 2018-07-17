#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MIN -999999999
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> vect;
	vect.push_back(MIN);

	int weight;
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight);
		if (vect.back() < weight)
			vect.push_back(weight);
		else {
			auto it = lower_bound(vect.begin(), vect.end(), weight);
			*it = weight;
		}
	}
	printf("%d\n", vect.size() - 1);
	return 0;
}