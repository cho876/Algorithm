#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;

	map<string, string> info;
	vector<pair< char*, int> > v_tmp;

	char* str;
	char* cmd;
	char* id;
	char* nick;

	for (int i = 0; i < record.size(); i++) {
		str = new char[record[i].size() + 1];
		strcpy(str, record[i].c_str());

		cmd = strtok(str, " ");
		if (!strcmp(cmd, "Enter")) {
			id = strtok(NULL, " ");
			nick = strtok(NULL, " ");
			info[string(id)] = string(nick);
			v_tmp.push_back({ id, 1 });
		}
		else if (!strcmp(cmd, "Leave")) {
			id = strtok(NULL, " ");
			v_tmp.push_back({ id, 2 });
		}
		else if (!strcmp(cmd, "Change")) {
			id = strtok(NULL, " ");
			nick = strtok(NULL, " ");
			info[string(id)] = string(nick);
		}
	}

	string ans;
	for (int i = 0; i < v_tmp.size(); i++) {
		ans = info[v_tmp[i].first];
		if (v_tmp[i].second == 1)
			ans.append("´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		else
			ans.append("´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		answer.push_back(ans);
	}

	return answer;
}

int main() {
	vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	solution(record);
}