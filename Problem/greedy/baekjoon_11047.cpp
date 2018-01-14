#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp_coins(int a, int b) { return a > b; }
void DFS(vector<int> v_coins, int index, int total_money, int& result);

int main()
{
	int number_of_coins;
	int limit_money;

	cin >> number_of_coins >> limit_money;
	vector<int> v_coins;

	int type_of_money;
	for (int i = 0; i < number_of_coins; i++) {
		cin >> type_of_money;
		v_coins.push_back(type_of_money);
	}

	sort(v_coins.begin(), v_coins.end(), cmp_coins);


	int result = 0;
	int index = 0;
	while (limit_money != 0) {
		if (v_coins[index] <= limit_money) {
			limit_money -= v_coins[index];
			result++;
		}
		else
			index++;
	}

	cout << result << endl;

	return 0;
}