#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MOD 10007
#define MAX 1001

using namespace std;

int dp[MAX];

int main() {
	int n;
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + (dp[i - 2] * 2)) % MOD;

	printf("%d\n", dp[n]);
}