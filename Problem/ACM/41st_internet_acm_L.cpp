/**
	The 41st Annual ACM
	Asia Regional-Daejeon
	Nationwide Internet Competition

	Probelm L (Trucks)
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> queue;

	int number_of_trucks;
	int bridge_length;
	int maximum_load;

	cin >> number_of_trucks >> bridge_length >> maximum_load;

	int tmp_truck_weight;
	int result = 0;
	int pos = 0;
	int cur_load = 0;

	for (int i = 0; i < number_of_trucks; i++) {
		cin >> tmp_truck_weight;

		while (1) {
			result++;

			if (pos >= bridge_length) {
				cur_load -= queue.front();
				queue.pop();
				pos--;
			}
			if (cur_load + tmp_truck_weight > maximum_load) {
				queue.push(0);
				pos++;
			}
			else {
				queue.push(tmp_truck_weight);
				cur_load += tmp_truck_weight;
				pos++;
				break;
			}
		}
	}

	cout << result + bridge_length << endl;
	return 0;
}