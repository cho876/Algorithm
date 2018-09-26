#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int fibonachi(int n) {
	int num1 = 0;
	int num2 = 1;
	int tmp;

	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else {
		for (int i = 0; i < n - 1; i++) {
			tmp = num2;
			num2 = num1 + num2;
			num1 = tmp;
		}
		return num2;
	}
}

int main() {
	int num;
	scanf("%d", &num);
	printf("%d", fibonachi(num));
}