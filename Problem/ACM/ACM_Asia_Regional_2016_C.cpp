#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Point {
	int pos;
	int kind;
};

bool cmp_point(Point a, Point b) { return a.pos < b.pos; }

int main()
{
	int total_kinds;
	int total_facilities;

	cin >> total_kinds >> total_facilities;

	vector<Point> v_point;
	Point point;
	int tmp_pos, tmp_kind;
	for (int i = 0; i < total_facilities; i++) {
		cin >> tmp_pos >> tmp_kind;
		point.pos = tmp_pos;
		point.kind = tmp_kind;
		v_point.push_back(point);
	}

	int* isExist = new int[total_kinds];
	for (int i = 0; i < total_kinds; i++)
		isExist[i] = 0;


	sort(v_point.begin(), v_point.end(), cmp_point);

	int left_index = 0;
	int right_index = 0;
	int res_L = 0;
	int res_R = 0;

	int cnt = 1;
	isExist[v_point[left_index].kind - 1] = 1;

	int dist = 9999999999;

	while (right_index < total_facilities) {
		if (cnt == total_kinds) {
			int center = (v_point[left_index].pos + v_point[right_index].pos) / 2;
			int cmp_max = max(abs(center - v_point[left_index].pos), abs(v_point[right_index].pos - center));

			if (cmp_max < dist) {
				dist = cmp_max;
				res_L = v_point[left_index].pos;
				res_R = v_point[right_index].pos;
			}

			isExist[v_point[left_index].kind - 1]--;

			if (!isExist[v_point[left_index].kind - 1])
				cnt--;
			left_index++;
		}
		else {
			right_index++;
			if (right_index < total_facilities) {
				if (!isExist[v_point[right_index].kind - 1])
					cnt++;
				isExist[v_point[right_index].kind - 1]++;
			}
		}
	}

	int result_dist = res_R - res_L;
	int result = res_L + (result_dist / 2);
	cout << result << endl;
}