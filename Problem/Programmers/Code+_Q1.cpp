#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

#define MAX 30
using namespace std;

int main() {
	vector<string> question;

	string str;
	getline(cin, str);
	question.push_back(str);

	vector<string> ans(MAX);
	string tmp;
	bool year_flag = false;
	bool month_flag = false;
	bool days_flag = false;
	int idx = 0;

	while (str != "END") {
		year_flag = false;
		month_flag = false;
		days_flag = false;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= '0' && str[i] <= '9')
				tmp.append(to_string(str[i] - '0'));
			else {
				if (!tmp.empty()) {
					if (!year_flag) {
						if (tmp.size() != 4)
							tmp.insert(0, "20");
						year_flag = true;
					}
					else if (!month_flag) {
						if (tmp.size() != 2)
							tmp.insert(0, "0");
						month_flag = true;
					}
					else if (!days_flag) {
						if (tmp.size() != 2)
							tmp.insert(0, "0");
						days_flag = true;
					}
					ans[idx].append(tmp);
					tmp = "";
				}
			}
			if (days_flag)
				break;
		}
		idx++;
		getline(cin, str);
		question.push_back(str);
	}

	vector<pair<string, int> > answer;
	for (int i = 0; i < idx; i++) 
		answer.push_back({ ans[i] ,i });

	sort(answer.begin(), answer.end());
	for (int i = 0; i < idx; i++)
		cout << question[answer[i].second] << endl;
}