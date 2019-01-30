#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

string convStr(int n, int num) {
	string res = "";

	while (true) {
		res = (num % n < 10 ? to_string(num%n) : string(1, num%n + 55)) + res;

		if (num / n == 0)
			break;

		num /= n;
	}
	return res;
}


int solution(int N) {
	string str = convStr(2, N);

	int maxValue = 0;
	int curValue = 0;

	int curIdx = 0;
	while (curIdx < str.size()) {
		while (str[curIdx] != '0') {
			curIdx++;
			if (curIdx == str.size())
				break;
		}

		while (str[curIdx] == '0') {
			curValue++;
			curIdx++;

			if (curIdx == str.size()) {	// ex) 100000....0
				break;
			}
			if (str[curIdx] != '0') {	// ex) 1001 -> End Index: 3
				maxValue = max(maxValue, curValue);
				curValue = 0;
				break;
			}
		}
	}
	cout << maxValue << endl;
	return maxValue;
}

int main() {
	int res = solution(20);
}