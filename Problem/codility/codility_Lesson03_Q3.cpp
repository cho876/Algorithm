#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> &A) {
	int sum = 0;

	for (int num : A)
		sum += num;

	int left = 0;
	int right = 0;
	int minValue = 987654321;

	for (int i = 0; i < A.size() - 1; i++) {
		left += A[i];
		sum -= A[i];

		minValue = min(minValue, abs(sum - left));
	}

	//cout << minValue << endl;
	return minValue;
}

int main() {
	vector<int> A = { 3,1,2,4,3 };
	int res = solution(A);

	return 0;
}