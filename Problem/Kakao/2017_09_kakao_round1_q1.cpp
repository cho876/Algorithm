/**
	Test Case

	5
	9 20 28 18 11
	30 1 21 17 28

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;

vector<int> arr1;
vector<int> arr2;
vector<char> res;

vector<int> getBin(int decimal) {
	vector<int> tmp;
	tmp.assign(n, 0);
	
	int index = n-1;
	while (decimal) {
		tmp[index--] = decimal % 2;
		decimal /= 2;
	}
	return tmp;
}

void getRes(vector<int> bin1, vector<int> bin2) {
	for (int i = 0; i < n; i++) {
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
		arr1.push_back(num);  // arr1 = [9, 20, 28, 18, 11]
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		arr2.push_back(num);   // arr2 = [30, 1, 21, 17, 28]
	}

	for (int i = 0; i < n; i++) {
		vector<int> bin1 = getBin(arr1[i]);
		vector<int> bin2 = getBin(arr2[i]);

		getRes(bin1, bin2);
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