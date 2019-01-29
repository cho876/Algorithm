#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#define MAX 26

using namespace std;

map<string, int> maps;
int idx = MAX;

vector<int> solution(string msg) {
	vector<int> res;

	for (int i = 1; i <= MAX; i++)
		maps[string(1, i + 64)] = i;

	while (!msg.empty()) {
		for (int i = msg.size(); i > 0; i--) {
			string key = msg.substr(0, i);
			auto iter = maps.find(key);
			if (iter != maps.end()) {
				string nextKey = (msg.size() > i + 1 ? msg.substr(i, 1) : "");
				
				if (!nextKey.empty())
					maps[key + nextKey] = ++idx;

				res.push_back(maps[key]);
				msg = msg.substr(key.size());
				break;
			}
		}
	}

	return res;
}

int main() {
	vector<int> res = solution("KAKAO");
	
	for (int num : res)
		cout << num << endl;

	return 0;
}