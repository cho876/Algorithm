#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

#define MAX 501

using namespace std;

int MOD = 20170805;

int r[MAX][MAX];
int d[MAX][MAX];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	memset(r, 0, sizeof(r));
	memset(d, 0, sizeof(d));

	MOD = 20170805;
	int answer = 0;

	r[1][1] = d[1][1] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (city_map[i - 1][j - 1] == 0) {
				r[i][j] = (r[i][j] + r[i][j - 1] + d[i - 1][j]) % MOD;
				d[i][j] = (d[i][j] + r[i][j - 1] + d[i - 1][j]) % MOD;
			}
			else if (city_map[i - 1][j - 1] == 1)
				r[i][j] = d[i][j] = 0;
			else {
				r[i][j] = r[i][j - 1];
				d[i][j] = d[i - 1][j];
			}
		}
	}
	answer = (r[m][n - 1] + d[m - 1][n]) % MOD;
	return answer;
}