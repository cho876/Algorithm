#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int lcsCnt;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	str1 = "0" + str1;
	str2 = "0" + str2;

	int len1 = str1.length();
	int len2 = str2.length();

	vector<int>* map = new vector<int>[len2];
	for (int i = 0; i < len2; i++)
		map[i].resize(len1, 0);

	int curMax;
	for (int i = 1; i < len2; i++) {
		curMax = 0;
		for (int j = 1; j < len1; j++) {
			if (str1[j] == str2[i]) {
				map[i][j] = map[i - 1][j - 1] + 1;
				curMax = map[i][j];
			}

			else {
				if (map[i - 1][j] > map[i][j - 1])
					map[i][j] = map[i - 1][j];
				else
					map[i][j] = map[i][j - 1];
			}
		}
		lcsCnt = max(lcsCnt, curMax);
	}
	printf("%d\n", lcsCnt);
}