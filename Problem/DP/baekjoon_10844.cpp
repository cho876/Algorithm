#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define MAX 1000000000

using namespace std;

int num[10];
int tmp[10];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i <= 9; i++)
		num[i] = 1;

	if (n == 1)
		printf("9\n");
	else {
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= 9; j++) {
				if (j == 0)
					tmp[j] = num[j + 1] % MAX;
				else if (j == 9)
					tmp[j] = num[j - 1] % MAX;
				else
					tmp[j] = (num[j - 1] + num[j + 1]) % MAX;
			}
			for (int k = 0; k <= 9; k++)
				num[k] = tmp[k];
		}
		int res = 0;
		for (int i = 1; i <= 9; i++)
			res = (res + num[i]) % MAX;

		printf("%d\n", res);
	}
}