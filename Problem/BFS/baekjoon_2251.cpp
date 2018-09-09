#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

#define MAX 201

using namespace std;

int N;
int A, B, C;
int isVisited[MAX][MAX];
int ansC[MAX];

struct Bottle {
	int a, b, c;
};

void bfs() {
	queue<Bottle> que;
	que.push({ 0,0,C });

	Bottle bottle;
	while (!que.empty()) {
		bottle = que.front();
		que.pop();

		if (isVisited[bottle.a][bottle.b])
			continue;

		isVisited[bottle.a][bottle.b] = true;

		if (bottle.a == 0)
			ansC[bottle.c] = true;

		// a -> b
		if (bottle.a + bottle.b > B)
			que.push({ (bottle.a + bottle.b) - B, B, bottle.c });
		else
			que.push({ 0, bottle.a + bottle.b, bottle.c });

		// a -> c
		if (bottle.a + bottle.c > C)
			que.push({ (bottle.a + bottle.c) - C, bottle.b, C });
		else
			que.push({ 0, bottle.b, bottle.a + bottle.c });

		// b -> a
		if (bottle.a + bottle.b > A)
			que.push({ A, (bottle.a + bottle.b) - A, bottle.c });
		else
			que.push({ bottle.a + bottle.b, 0, bottle.c });

		// b -> c
		if (bottle.b + bottle.c > C)
			que.push({ bottle.a, (bottle.b + bottle.c) - C, C });
		else
			que.push({ bottle.a, 0, bottle.b + bottle.c });

		// c -> a
		if (bottle.a + bottle.c > A)
			que.push({ A, bottle.b, (bottle.a + bottle.c) - A });
		else
			que.push({ bottle.a + bottle.c, bottle.b, 0 });

		// c -> b
		if (bottle.b + bottle.c > B)
			que.push({ bottle.a, B, (bottle.b + bottle.c) - B });
		else
			que.push({ bottle.a, bottle.b + bottle.c, 0 });
	}
}

int main() {
	scanf("%d%d%d", &A, &B, &C);
	bfs();

	for (int i = 0; i < MAX; i++)
		if (ansC[i])
			printf("%d ", i);

	return 0;
}