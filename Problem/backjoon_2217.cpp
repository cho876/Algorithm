#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int total_ropes;
	cin >> total_ropes;
	vector<int> v_ropes;

	int tmp_weight;
	for (int i = 0; i < total_ropes; i++) {
		cin >> tmp_weight;
		v_ropes.push_back(tmp_weight);
	}

	sort(v_ropes.begin(), v_ropes.end());

	int result = 0;

	for (int i = 0; i < v_ropes.size(); i++) {
		result = max(result, v_ropes[i] * (total_ropes - i));
	}
	cout << result << endl;

	return 0;
}