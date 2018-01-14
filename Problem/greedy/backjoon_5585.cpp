#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int pay;
	cin >> pay;
	
	vector<int> v_type;
	v_type.push_back(500);
	v_type.push_back(100);
	v_type.push_back(50);
	v_type.push_back(10);
	v_type.push_back(5);
	v_type.push_back(1);

	int last = 1000 - pay;
	int count = 0;
	int index = 0;
	
	while (last != 0) {
		if (v_type[index] <= last) {
			count++;
			last -= v_type[index];
		}
		else
			index++;
	}

	cout << count << endl;
}