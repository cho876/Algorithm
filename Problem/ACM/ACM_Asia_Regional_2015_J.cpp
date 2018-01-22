#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool DFS(vector<int> v_prime, int index1, int index2, int index3, int num);
void getPrime(int num, vector<int>& v_prime);

int main()
{
	int test;
	scanf("%d", &test);

	for (int i = 0; i < test; i++) {
		int num;
		scanf("%d", &num);

		vector<int> v_prime;

		getPrime(num, v_prime);

		bool flag = DFS(v_prime, 0, 0, 0, num);

		if (!flag)
			printf("0\n");
	}
	return 0;
}

bool DFS(vector<int> v_prime, int index1, int index2, int index3, int num) {
	if (index1 >= v_prime.size() || index2 >= v_prime.size() || index3 >= v_prime.size())
		return false;
	else {
		int curNum1 = v_prime[index1];
		int curNum2 = v_prime[index2];
		int curNum3 = v_prime[index3];

		if (curNum1 + curNum2 + curNum3 == num) {
			printf("%d %d %d\n", curNum1, curNum2, curNum3);
			return true;
		}
		else {
			if (!DFS(v_prime, index1, index2, index3 + 1, num)) {
				if (!DFS(v_prime, index1, index2 + 1, index3 + 1,num)) {
					if (!DFS(v_prime, index1 + 1, index2 + 1, index3 + 1, num))
						return false;
				}
			}
			return true;
		}
	}
}

void getPrime(int num, vector<int>& v_prime) {
	vector<bool> isPrime;
	isPrime.resize(num + 1);

	for (int i = 2; i <= num; i++)
		isPrime[i] = true;

	for (int i = 2; i <= num; i++) {
		for (int j = i + i; j <= num; j += i)
			isPrime[j] = false;
	}

	for (int i = 2; i <= num; i++) {
		if (isPrime[i])
			v_prime.push_back(i);
	}
}