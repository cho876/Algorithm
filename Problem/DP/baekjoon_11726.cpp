#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
	if (n == 1)
		return 1;

	else {
		int res = 0;
		int left = 1;
		int right = 1;

		for (int i = 2; i <= n; i++){
			res = (left + right) % 10007;
			left = right;
			right = res;
		}
		return res % 10007;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int res = solution(n);
	printf("%d\n", res);
}