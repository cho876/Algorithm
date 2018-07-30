#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

#define MAX 1000000

using namespace std;

int arrows[MAX];
int res;

int main() {
	int n;
	scanf("%d", &n);

	memset(arrows, 0, sizeof(arrows));

	int height;
	for (int i = 0; i < n; i++) {
		scanf("%d", &height);
		if (arrows[height] > 0)
			arrows[height]--;

		arrows[--height]++;
	}

	for (int i = 0; i < n + 1; i++)
		res += arrows[i];

	printf("%d\n", res);
	return 0;
}