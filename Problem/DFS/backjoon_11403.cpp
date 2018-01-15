#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int N;
	cin >> N;

	vector<bool>* v_list = new vector<bool>[N];

	bool isExist;
	for (int i = 0; i < N; i++) {
		v_list[i].resize(N);
		for (int j = 0; j < N; j++) {
			cin >> isExist;
			v_list[i][j] = isExist;
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (v_list[i][k] && v_list[k][j])
					v_list[i][j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << v_list[i][j] << " ";
		cout << endl;
	}

	return 0;
}