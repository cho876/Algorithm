#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>

#define MAX 10001

using namespace std;

bool isVisited[MAX];
bool isPrime[MAX];
int dist[MAX];

void setPrime() {
	for (int i = 2; i < MAX; i++) {
		for (int j = i * i; j < MAX; j += i)
			isPrime[j] = false;
	}
}

int change(int num, int index, int digit) {
	if (index == 0 && digit == 0)
		return -1;

	string temp = to_string(num);
	temp[index] = digit + '0';
	return stoi(temp);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(isPrime, true, sizeof(isPrime));
		memset(isVisited, false, sizeof(isVisited));
		memset(dist,0, sizeof(dist));

		setPrime();

		int num1, num2;
		scanf("%d%d", &num1, &num2);

		queue<int> que;
		isVisited[num1] = true;
		dist[num1] = 0;
		que.push(num1);

		int curNum, nextNum;
		while (!que.empty()) {
			curNum = que.front();
			que.pop();

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					nextNum = change(curNum, i, j);
					if (isPrime[nextNum] && !isVisited[nextNum]) {
						isVisited[nextNum] = true;
						dist[nextNum] = dist[curNum] + 1;
						que.push(nextNum);
					}
				}
			}
		}
		printf("%d\n", dist[num2]);
	}
	return 0;
}