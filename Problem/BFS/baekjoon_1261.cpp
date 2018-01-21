#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct Point {
	int dx;
	int dy;
	int cnt;

public:
	Point(int dx, int dy, int cnt) :dx(dx), dy(dy), cnt(cnt) {}

	bool operator< (Point p)const { return cnt > p.cnt; }
};

int mr[4] = { 1,-1,0,0 };
int mc[4] = { 0,0,1,-1 };

int main()
{
	int row, col;
	scanf("%d%d", &col, &row);

	char map[100][100];
	for (int i = 0; i < row; i++) {
		scanf("%s", map[i]);
	}


	bool isVisited[100][100] = { 0, };

	priority_queue<Point> q_list;
	q_list.push(Point(0, 0, 0));

	int curDx, curDy, curCnt;
	while (!q_list.empty()) {
		curDx = q_list.top().dx;
		curDy = q_list.top().dy;
		curCnt = q_list.top().cnt;

		q_list.pop();

		if (curDx == col - 1 && curDy == row - 1) {
			printf("%d\n", curCnt);
			break;
		}

		isVisited[curDy][curDx] = true;

		int nextDx, nextDy;
		for (int i = 0; i < 4; i++) {
			nextDx = curDx + mc[i];
			nextDy = curDy + mr[i];

			if (nextDx < 0 || nextDy < 0 || nextDx >= col || nextDy >= row)
				continue;

			if (isVisited[nextDy][nextDx])
				continue;

			if (map[nextDy][nextDx] == '1')
				q_list.push(Point(nextDx, nextDy, curCnt + 1));
			else
				q_list.push(Point(nextDx, nextDy, curCnt));
		}
	}
}