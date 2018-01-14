#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
	int start;
	int end;
};

bool cmp_sort(Info a, Info b) { return a.end < b.end; }

int main()
{
	int number_of_room;
	cin >> number_of_room;
	vector<Info> v_meet;

	int tmp_start;
	int tmp_end;
	Info info;
	for (int i = 0; i < number_of_room; i++) {
		cin >> tmp_start >> tmp_end;
		info.start = tmp_start;
		info.end = tmp_end;
		v_meet.push_back(info);
	}
	sort(v_meet.begin(), v_meet.end(), cmp_sort);

	int result = 0;
	int start_point = -99999;

	for (int i = 0; i < v_meet.size(); i++) {
		if (start_point <= v_meet[i].start) {
			result++;
			start_point = v_meet[i].end;
		}
	}

	cout << result << endl;
}
