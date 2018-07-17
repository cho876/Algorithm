#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int strSize = 0;
stack<int> stk;

void strToken(char* str) {
	int tmp = 0;
	int pre = 0;
	for (int i = 0; i < strSize; i++) {
		switch (str[i]) {
		case '*':
			tmp = stk.top() * 2;
			stk.pop();
			if (!stk.empty()) {
				pre = stk.top() * 2;
				stk.pop();
				stk.push(pre);
			}
			stk.push(tmp);
			break;

		case '#':
			tmp = stk.top() * (-1);
			stk.pop();
			stk.push(tmp);
			break;

		case 'S':
			tmp = pow(stk.top(), 1);
			stk.pop();
			stk.push(tmp);
			break;

		case 'D':
			tmp = pow(stk.top(), 2);
			stk.pop();
			stk.push(tmp);
			break;

		case 'T':
			tmp = pow(stk.top(), 3);
			stk.pop();
			stk.push(tmp);
			break;

		case '0':
			if (!stk.empty()) {
				stk.pop();
				stk.push(10);
			}
			else
				stk.push(0);
			break;

		default:
			tmp = str[i] - '0';
			stk.push(tmp);
		}
	}
}

int main() {
	string str;
	cin >> str;
	strSize = str.size();

	char* cStr = new char[str.size() + 1];
	strcpy(cStr, str.c_str());

	strToken(cStr);

	int res = 0;
	while (!stk.empty()) {
		res += stk.top();
		stk.pop();
	}
	printf("%d\n", res);
	return 0;
}