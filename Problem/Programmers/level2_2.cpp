#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
#include<string>
#include <iostream>

using namespace std;

bool solution(string str)
{
	bool answer = true;

	int left = 0;
	int right = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			left++;
		else if (str[i] == ')')
			right++;

		if (right > left)
			answer = false;
	}
	if (left != right)
		answer = false;

	return answer;
}

int main() {
	string str;
	cin >> str;
	if (solution(str))
		printf("true");
	else
		printf("false");
}