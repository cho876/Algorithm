#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp_sort(int a, int b) { return a > b; }

int main()
{
	string str_num;
	cin >> str_num;
	vector<int> v_list;

	int sum = 0;
	for (int i = 0; i < str_num.length(); i++) {
		v_list.push_back(str_num[i] - '0');
		sum += v_list[i];
	}

	if (sum % 3 == 0) {
		sort(v_list.begin(), v_list.end(), cmp_sort);
		if (v_list[v_list.size() - 1] == 0) {
			for (int i = 0; i < v_list.size(); i++)
				cout << v_list[i];
			return 0;
		}
	}

	cout << "-1" << endl;
	return 0;
}