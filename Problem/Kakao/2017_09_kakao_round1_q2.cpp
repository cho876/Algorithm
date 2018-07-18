/**
	Test Case

	1S2D*3T
	1D2S#10S
	1D2S0T
	1S*2T*3S
	1D#2S*3S
	1T2D3D#
	1D2S3T*
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> stk;

int main() {
	string str;
	cin >> str;

	char* cStr = new char[str.length() + 1];
	strcpy(cStr, str.c_str());

	for (int i = 0; i < str.length(); i++) {
		int calc = 0;
		int pre = 0;
		switch (cStr[i]) {
		case '*':
			calc = stk.top() * 2;
			stk.pop();
			if (!stk.empty()) {
				pre = stk.top() * 2;
				stk.pop();
				stk.push(pre);
			}
			stk.push(calc);
			break;

		case '#':
			calc = stk.top() * (-1);
			stk.pop();
			stk.push(calc);
			break;
		
		case 'S':
			calc = pow(stk.top(), 1);
			stk.pop();
			stk.push(calc);
			break;

		case 'D':
			calc = pow(stk.top(), 2);
			stk.pop();
			stk.push(calc);
			break;

		case 'T':
			calc = pow(stk.top(), 3);
			stk.pop();
			stk.push(calc);
			break;

		case '0':
			if (stk.top() == 1) {
				stk.pop();
				stk.push(10);
			}
			else
				stk.push(0);
			break;

		default:
			stk.push(cStr[i] - '0');
		}
	}
	int res = 0;
	while (!stk.empty()){
		res += stk.top();
		stk.pop();
	}
	printf("%d", res);
	return 0;
}