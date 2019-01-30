#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int solution(vector<int> &A) {

	sort(A.begin(), A.end());

	int i = 0;
	for (i = 0; i < A.size(); i++) {
		if (i + 1 != A[i])
			return i + 1;
	}

	return A.size() + 1;
}

int main() {
	vector<int> A = { 3,5,2,1,6,9,7,10,4 };
	int res = solution(A);

	return 0;
}