#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Point {
	int dx;
	int dy;
	int pay;

public:
	Point(int dx, int dy, int pay) :dx(dx), dy(dy), pay(pay) {}
	bool operator< (Point p)const { return pay > p.pay; }
};

int mr[4] = { 1,-1,0,0 };
int mc[4] = { 0,0,1,-1 };

int main()
{
	vector<int> v_result;

	while (1) {
		int size;
		scanf("%d", &size);

		if (size == 0)
			break;
		vector<int>* v_list = new vector<int>[size];

		int value;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				scanf("%d", &value);
				v_list[i].push_back(value);
			}
		}

		bool isVisited[125][125] = { 0, };

		priority_queue<Point> q_list;
		q_list.push(Point(0, 0, v_list[0][0]));

		int curDx, curDy, curPay;
		while (!q_list.empty()) {
			curDx = q_list.top().dx;
			curDy = q_list.top().dy;
			curPay = q_list.top().pay;
			q_list.pop();

			if (curDx == size - 1 && curDy == size - 1) {
				v_result.push_back(curPay);
				break;
			}

			isVisited[curDy][curDx] = true;

			int nextDx, nextDy;
			for (int i = 0; i < 4; i++) {
				nextDx = curDx + mc[i];
				nextDy = curDy + mr[i];

				if (nextDx < 0 || nextDy < 0 || nextDx >= size || nextDy >= size)
					continue;

				if (isVisited[nextDy][nextDx])
					continue;

				q_list.push(Point(nextDx, nextDy, curPay + v_list[nextDy][nextDx]));
			}
		}
	}

	for (int i = 0; i < v_result.size(); i++)
		printf("Problem %d: %d\n", i + 1, v_result[i]);
	return 0;
}