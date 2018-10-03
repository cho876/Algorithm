#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

vector<int> vec;
vector<vector<int> > answer;

int main() {
	string str;
	int total;
	getline(cin, str);
	scanf("%d", &total);

	char* cStr = (char*)calloc(str.size() + 1, sizeof(char));
	strcpy(cStr, str.c_str());

	char* ch = strtok(cStr, " ");
	while (ch != NULL) {
		vec.push_back(atoi(ch));
		ch = strtok(NULL, " ");
	}
	sort(vec.begin(), vec.end());

	vector<int> tmp;
	int sum = 0;
	do {
		for (int i = 0; i < 3; i++) {
			sum += vec[i];
			tmp.push_back(vec[i]);
		}

		if (sum == total) {
			sort(tmp.begin(), tmp.end());
			answer.push_back(tmp);
		}
		tmp.clear();
		sum = 0;
	} while (next_permutation(vec.begin(), vec.end()));
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	if (answer.empty())
		printf("NO\n");
	else {
		for (int i = 0; i < answer.size(); i++) {
			for (int j = 0; j < answer[i].size(); j++)
				printf("%d ", answer[i][j]);
			printf("\n");
		}
	}
}