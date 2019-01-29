#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string convStr(int n, int num) {
	string res = "";

	if (num == 0)
		return "0";

	while (true) {
		res = (num % n < 10 ? to_string(num%n) : string(1, num%n + 55)) + res;
		if (num / n == 0)
			break;
		num /= n;
	}

	return res;
}

string solution(int n, int t, int m, int p) {
	string res = "";
	string curStr = "";
	int curNum = 0;
	int curTurn = 0;

	while (res.size() < t) {
		curStr = convStr(n, curNum++);
		for (char ch : curStr) {
			++curTurn;
			if (curTurn == p) {
				res += ch;
				if (res.size() == t)
					break;
			}
			if (curTurn == m)
				curTurn = 0;
		}
	}

	return res;
}

int main() {
	string res = solution(2, 4, 2, 1);
	cout << res << endl;

	return 0;
}