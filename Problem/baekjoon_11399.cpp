#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int people;
	cin >> people;
	vector<int> v_line;

	int tmp_time;
	for (int i = 0; i < people; i++) {
		cin >> tmp_time;
		v_line.push_back(tmp_time);
	}

	sort(v_line.begin(), v_line.end());

	int sum = v_line[0];
	for (int i = 1; i < v_line.size(); i++) {
		v_line[i] += v_line[i - 1];
		sum += v_line[i];
	}
	cout << sum << endl;
}