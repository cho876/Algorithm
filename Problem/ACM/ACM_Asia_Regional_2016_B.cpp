#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isCorrect(vector<int> v_games, int index, int curTotal);

int main()
{
	int number_of_team;
	cin >> number_of_team;

	vector<int> v_teams;
	int tmp_score;
	for (int i = 0; i < number_of_team; i++) {
		cin >> tmp_score;
		v_teams.push_back(tmp_score);
	}

	sort(v_teams.begin(), v_teams.end());

	if (isCorrect(v_teams, 0, 0))
		cout << "1" << endl;
	else
		cout << "-1" << endl;

	return 0;

}

bool isCorrect(vector<int> v_games, int index, int curTotal) {
	if (index >= v_games.size()) {
		if (curTotal == index * (index - 1) / 2) 
			return true;
		else
			return false;
	}
	else {
		curTotal += v_games[index];
		if (curTotal >= index * (index + 1) / 2) {
			return isCorrect(v_games, index + 1, curTotal);
		}
		else
			return false;
	}
}