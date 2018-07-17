#include <iostream>
#include <cstdio>
#include <vector>

#define MAX 17

using namespace std;

vector<int> bin1;
vector<int> bin2;
vector<int> arr1;
vector<int> arr2;

vector<char> res;

int n;

vector<int> getBin(int decimal) {
	vector<int> tmp;
	tmp.resize(n);

	int index = n-1;
	while (decimal) {
		tmp[index--] = decimal % 2;
		decimal /= 2;
	}
	return tmp;
}

void cmpBin(vector<int> bin1, vector<int> bin2) {
	for (int i = 0; i < bin1.size(); i++) {
		if (bin1[i] == 1 || bin2[i] == 1)
			res.push_back('#');
		else
			res.push_back(' ');
	}
}

int main() {
	scanf("%d", &n);

	int num;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		arr1.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		arr2.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		bin1 = getBin(arr1[i]);
		bin2 = getBin(arr2[i]);
		cmpBin(bin1, bin2);
	}

	int cnt = 0;
	for (int i = 0; i < res.size(); i++) {
		cnt++;
		printf("%c", res[i]);
		if (cnt % n == 0)
			printf("\n");
	}

	return 0;
}