#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

#define INF 98765432
#define MIN -98765432

using namespace std;

string solution(string s) {
	string answer = "";

	char* cStr = new char[s.length() + 1];
	strcpy(cStr, s.c_str());

	char* ptr = strtok(cStr, " ");
	int curValue = 0;
	int minValue = INF;
	int maxValue = MIN;

	while (ptr != NULL) {
		curValue = atoi(ptr);
		minValue = min(curValue, minValue);
		maxValue = max(curValue, maxValue);
		ptr = strtok(NULL, " ");
	}
	answer = to_string(minValue) + " " + to_string(maxValue);
	return answer;
}