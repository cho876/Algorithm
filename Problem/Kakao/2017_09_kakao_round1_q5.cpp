/**
	Test Case

	FRANCE
	french

	handshake
	shake hands

	aa1+aa2
	AAAA12

	E=M*C^2
	e=m*c^2
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

#define MAX 1001

using namespace std;

char str1[MAX];
char str2[MAX];

vector<string> vec1;
vector<string> vec2;

float intersect;
float unionsect;

bool isValid(string str) {
	bool valid = true;
	for (int i = 0; i < str.size(); i++) {
		if ('A' > str[i] || str[i] > 'Z')
			valid = false;
	}
	return valid;
}

vector<string> getSplit(string str) {
	vector<string> tmp;
	for (int i = 0; i < str.size() - 1; i++) {
		string subStr = str.substr(i, 2);
		if (isValid(subStr))
			tmp.push_back(subStr);
	}
	return tmp;
}

void getIntersect(vector<string> vec1, vector<string> vec2) {
	vector<string> tmp1 = vec1;
	vector<string> tmp2 = vec2;

	for (string cmp1 : tmp1) {
		auto iter = find(tmp2.begin(), tmp2.end(), cmp1);
		if (iter != tmp2.end())
			intersect++;
	}
}

void getUnion(vector<string> vec1, vector<string> vec2) {
	vector<string> tmp1 = vec1;
	vector<string> tmp2 = vec2;

	for (string cmp1 : tmp1) {
		auto iter = find(tmp2.begin(), tmp2.end(), cmp1);
		if (iter != tmp2.end())
			tmp2.erase(iter);
	}
	unionsect = tmp1.size() + tmp2.size();
}

int main() {
	cin.getline(str1, MAX);
	cin.getline(str2, MAX);

	string s_str1(str1);
	string s_str2(str2);

	transform(s_str1.begin(), s_str1.end(), s_str1.begin(), toupper);
	transform(s_str2.begin(), s_str2.end(), s_str2.begin(), toupper);

	vec1 = getSplit(s_str1);
	vec2 = getSplit(s_str2);

	getUnion(vec1, vec2);
	getIntersect(vec1, vec2);

	float subDev = 0;
	if (intersect == 0 && unionsect == 0)
		subDev = 1.0;
	else
		subDev = intersect / unionsect;

	float res = subDev * 65536;
	printf("%.f\n", floor(res));

	return 0;
}