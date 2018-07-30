#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX 1001

using namespace std;

int len1, len2;
int LCS_result;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	str1 = "0" + str1;
	str2 = "0" + str2;

	len1 = str1.length();
	len2 = str2.length();

	vector<int>* map = new vector<int>[len2];

	for (int i = 0; i < len2; i++)
		map[i].resize(len1, 0);

	int maxValue;
	for (int i = 1; i < len2; i++) {
		maxValue = 0;
		for (int j = 1; j < len1; j++) {
			if (str1[j] == str2[i]) {
				maxValue = map[i - 1][j - 1] + 1;
				map[i][j] = maxValue;
			}
			else {
				if (map[i - 1][j] > map[i][j - 1])
					map[i][j] = map[i - 1][j];
				else
					map[i][j] = map[i][j - 1];
			}
		}
		LCS_result = max(LCS_result, maxValue);
	}

	int tmp1 = LCS_result;
	int tmp0 = LCS_result - 1;
	int range = len1 - 1;
	string s_res = "";

	for (int i = len2 - 1; i > 0; i--) {
		for (int j = range; j > 0; j--) {
			if (map[i][j] == tmp1 && map[i - 1][j - 1] == tmp0 && map[i][j - 1] == tmp0 && map[i - 1][j] == tmp0) {
				tmp1--;
				tmp0--;
				range = j;
				s_res = str2[i] + s_res;
				break;
			}
		}
	}
	cout << s_res << endl;
}