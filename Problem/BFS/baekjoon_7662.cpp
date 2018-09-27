#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <queue>
#include <stdlib.h>

using namespace std;

string solution(vector<string> example){
	string answer;

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > min_que;
	priority_queue<pair<int, int> > max_que;

	char* str;
	char* cmd;
	char* num;
	int value = 0;
	bool* isVisited = (bool*)calloc(example.size(), sizeof(bool));

	for (int i = 0; i < example.size(); i++) {
		str = (char*)malloc(example[i].size() + 1);
		strcpy(str, example[i].c_str());

		cmd = strtok(str, " ");
		if (!strcmp(cmd, "I")) {
			num = strtok(NULL, " ");
			value = atoi(num);
			max_que.push({ value, i });
			min_que.push({ value, i });
		}
		else if (!strcmp(cmd, "D")) {
			num = strtok(NULL, " ");
			value = atoi(num);
			if (value == 1) {
				if (!max_que.empty()) {
					if (!isVisited[max_que.top().second]) {
						isVisited[max_que.top().second] = true;
						max_que.pop();
					}
				}
			}
			else if (value == -1) {
				if (!min_que.empty()) {
					if (!isVisited[min_que.top().second]) {
						isVisited[min_que.top().second] = true;
						min_que.pop();
					}
				}
			}
			while (!max_que.empty() && isVisited[max_que.top().second])
				max_que.pop();
			while (!min_que.empty() && isVisited[min_que.top().second])
				min_que.pop();
		}
		free(str);
	}
	free(isVisited);
	if (max_que.empty() && min_que.empty())
		answer = "EMPTY";
	else {
		answer = to_string(max_que.top().first);
		answer.append(" ");
		answer.append(to_string(min_que.top().first));
	}
	return answer;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d ", &n);
		vector<string> example;
		string tmp;
		for (int i = 0; i < n; i++) {
			getline(cin, tmp);
			example.push_back(tmp);
		}
		cout << solution(example)<<endl;
	}
}