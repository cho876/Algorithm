#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

void hiber(int x, int y, int length, int move, int type);

int main()
{
	int length;
	int move;

	cin >> length >> move;

	int total_points = pow(length, 2) / 4;

	hiber(1, 1, length, move, 1);

	return 0;
}

void hiber(int x, int y, int length, int move, int type) {
	if (length == 1)
		cout << x << " " << y << endl;
	else {
		int cur_length = length / 2;
		int total_points = pow(length, 2) / 4;

		if (type == 1) {
			if (0 < move && move <= total_points)
				hiber(x, y, cur_length, move, 3);
			else if (total_points < move && move <= 2 * total_points)
				hiber(x, y + cur_length, cur_length, move - total_points, 1);
			else if (2 * total_points < move && move <= 3 * total_points)
				hiber(x + cur_length, y + cur_length, cur_length, move - 2 * total_points, 1);
			else
				hiber(x + length - 1, y + cur_length - 1, cur_length, move - 3 * total_points, 4);
		}
		else if (type == 2) {
			if (0 < move && move <= total_points)
				hiber(x, y, cur_length, move, 4);
			else if (total_points < move && move <= 2 * total_points)
				hiber(x, y - cur_length, cur_length, move - total_points, 2);
			else if (2 * total_points < move && move <= 3 * total_points)
				hiber(x - cur_length, y - cur_length, cur_length, move - 2 * total_points, 2);
			else
				hiber(x - length + 1, y - cur_length + 1, cur_length, move - 3 * total_points, 3);
		}
		else if (type == 3) {
			if (0 < move && move <= total_points)
				hiber(x, y, cur_length, move, 1);
			else if (total_points < move && move <= 2 * total_points)
				hiber(x + cur_length, y, cur_length, move - total_points, 3);
			else if (2 * total_points < move && move <= 3 * total_points)
				hiber(x + cur_length, y + cur_length, cur_length, move - 2 * total_points, 3);
			else
				hiber(x + cur_length - 1, y + length - 1, cur_length, move - 3 * total_points, 2);
		}
		else {
			if (0 < move && move <= total_points)
				hiber(x, y, cur_length, move, 2);
			else if (total_points < move && move <= 2 * total_points)
				hiber(x - cur_length, y, cur_length, move - total_points, 4);
			else if (2 * total_points < move && move <= 3 * total_points)
				hiber(x - cur_length, y - cur_length, cur_length, move - 2 * total_points, 4);
			else
				hiber(x - cur_length + 1, y - length + 1, cur_length, move - 3 * total_points, 1);
		}
	}
}