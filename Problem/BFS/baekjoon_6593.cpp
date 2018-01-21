#include <iostream>
#include <cstdio>
#include <queue>

#define MAX 30
using namespace std;

class Point {
public:
	int dx;
	int dy;
	int dz;
	int time;

public:
	Point(int dx, int dy, int dz, int time) :dx(dx), dy(dy), dz(dz), time(time) {}
};

int mx[6] = { 1,-1,0,0,0,0 };
int my[6] = { 0,0,1,-1,0,0 };
int mz[6] = { 0,0,0,0,1,-1 };

int main()
{
	while (1) {
		int x, y, z;
		scanf("%d%d%d", &z, &y, &x);

		if (x == 0 && y == 0 && z == 0)
			break;

		char map[MAX][MAX][MAX];
		bool isVisited[MAX][MAX][MAX];

		bool flag = false;
		queue<Point> q_list;

		for (int i = 0; i < z; i++) {
			for (int j = 0; j < y; j++) {
				scanf("%s", map[i][j]);
				for (int k = 0; k < x; k++) {
					isVisited[i][j][k] = false;
					if (map[i][j][k] == 'S') {
						isVisited[k][j][i] = true;
						q_list.push(Point(k, j, i, 0));
					}
				}
			}
		}

		int curDx, curDy, curDz, curTime, nextDx, nextDy, nextDz;

		while (!q_list.empty()) {
			curDx = q_list.front().dx;
			curDy = q_list.front().dy;
			curDz = q_list.front().dz;
			curTime = q_list.front().time;
			q_list.pop();

			if (map[curDz][curDy][curDx] == 'E') {
				printf("Escaped in %d minute(s).\n", curTime);
				flag = true;
				break;
			}

			for (int i = 0; i < 6; i++) {
				nextDx = curDx + mx[i];
				nextDy = curDy + my[i];
				nextDz = curDz + mz[i];

				if (nextDx < 0 || nextDy < 0 || nextDz < 0 || nextDx >= x || nextDy >= y || nextDz >= z)
					continue;

				if (isVisited[nextDz][nextDy][nextDx])
					continue;

				if (map[nextDz][nextDy][nextDx] == '#')
					continue;

				isVisited[nextDz][nextDy][nextDx] = true;

				q_list.push(Point(nextDx, nextDy, nextDz, curTime + 1));
			}
		}

		if (!flag)
			printf("Trapped!\n");
	}
}