#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

bool cmp_user(pair<int, double> p1, pair<int, double> p2) {
	if (p1.second != p2.second)
		return p1.second > p2.second;
	else
		return p1.first < p2.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	sort(stages.begin(), stages.end(), greater<int>());

	vector<pair<int, double> > tmp;
	int totalChallenger = 0;
	int trial = 0;
	for (int round = 1; round <= N; round++) {
		totalChallenger = stages.size();
		trial = 0;
		for (int i = stages.size() - 1; i >= 0; i--) {
			if (round == stages[i]) {
				trial++;
				stages.pop_back();
			}
		}
		if (trial == 0)
			tmp.push_back({ round, 0 });
		else
			tmp.push_back({ round, trial / (double)totalChallenger });
	}
	sort(tmp.begin(), tmp.end(), cmp_user);

	for (int i = 0; i < tmp.size(); i++)
		answer.push_back(tmp[i].first);

	return answer;
}

int main() {
	int N = 10;
	vector<int> stages = { 5,6,6,3,2,5,2,1,3,10,11};
	solution(N, stages);
}