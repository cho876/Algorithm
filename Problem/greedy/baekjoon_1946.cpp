#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Score {
	int first;
	int second;
};

bool cmp_sort(Score a, Score b) { return a.first < b.first; }

int main() {
	int test_case;
	cin >> test_case;

	vector<int> v_result;

	int support;
	int first_score;
	int second_score;

	Score score;
	for (int i = 0; i < test_case; i++) {
		cin >> support;
		vector<Score> v_score;
		for (int i = 0; i < support; i++) {
			cin >> first_score >> second_score;
			score.first = first_score;
			score.second = second_score;
			v_score.push_back(score);
		}
		sort(v_score.begin(), v_score.end(), cmp_sort);

		int min_score = v_score[0].second;
		int result = 1;
		for (int i = 1; i < v_score.size(); i++) {
			if (min_score > v_score[i].second) {
				result++;
				min_score = v_score[i].second;
			}
		}
		v_result.push_back(result);
	}

	for (int i = 0; i < v_result.size(); i++)
		cout << v_result[i] << endl;

	return 0;
}