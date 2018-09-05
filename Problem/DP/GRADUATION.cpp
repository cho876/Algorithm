/*
	N���� ���� ��, �ּ� K���� ���Ǹ� �����ؾ��Ѵ�.
	M���� �б�� �̷���� �ְ�, �� �б�� L���� ������ �����ȴ�.

	�̶�, �ּ����� �б�� ������ �� �� �ִ� �б� ���� ����϶�.

	1 line) N, K, M, L

	2 line) N���� ���Ǵ� �������� ���� & �������� �ε���

	3 line) M���� �б�� ���� ���� & ���ǰ��� �ε���

	TestCase

	4 4 4 4
	0
	1 0
	3 0 1 3
	0
	4 0 1 2 3
	4 0 1 2 3
	3 0 1 3
	4 0 1 2 3
	----------

	4 2 2 4
	1 1
	0
	1 3
	1 2
	3 0 2 3
	3 1 2 3
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>

#define INF 987654321
#define MAXN 4

using namespace std;

int N, K, M, L;
int semester[8];
int prerequisite[8];
int cache[8][1 << MAXN];

int bitCount(int num) {
	if (num == 0)
		return 0;
	else
		return num % 2 + bitCount(num / 2);
}

int graduate(int curSemester, int taken) {
	if (bitCount(taken) >= K)
		return 0;
	if (curSemester == M)
		return INF;

	int& ret = cache[curSemester][taken];
	if (ret != -1)
		return ret;

	ret = INF;

	int canTake = (semester[curSemester] & ~taken);

	for (int i = 0; i < N; i++) {
		if ((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);
	}

	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		if (bitCount(take) > L)
			continue;
		ret = min(ret, graduate(curSemester + 1, take | taken) + 1);
	}
	ret = min(ret, graduate(curSemester + 1, taken));
	return ret;
}

int main() {
	scanf("%d%d%d%d", &N, &K, &M, &L);

	for (int i = 0; i < 8; i++)
		memset(cache[i], -1, sizeof(int) * (1 << MAXN));

	int cnt, adj;
	for (int i = 0; i < N; i++) {
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			scanf("%d", &adj);
			prerequisite[i] += (1 << adj);
		}
	}

	for (int i = 0; i < M; i++) {
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			scanf("%d", &adj);
			semester[i] += (1 << adj);
		}
	}

	int res = graduate(1, 0);
	if (res == INF)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", res);

	return 0;
}