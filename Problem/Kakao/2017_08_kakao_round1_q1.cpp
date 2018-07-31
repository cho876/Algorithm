#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 101
using namespace std;

int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool isVisited[MAX][MAX];
queue<pair<int, int> > que;

int setMove(vector<vector<int>> picture, int& number_of_area, int maxRow, int maxCol) {
	number_of_area++;

	int dist = 1;
	int curRow, curCol, nextRow, nextCol;
	int index = picture[que.front().first][que.front().second];

	while (!que.empty()) {
		curRow = que.front().first;
		curCol = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			nextRow = curRow + movement[i][0];
			nextCol = curCol + movement[i][1];

			if (nextRow >= maxRow || nextRow < 0 || nextCol >= maxCol || nextCol < 0)
				continue;
			else if (isVisited[nextRow][nextCol])
				continue;

			if (picture[nextRow][nextCol] == index) {
				isVisited[nextRow][nextCol] = true;
				que.push({ nextRow, nextCol });
				dist++;
			}
		}
	}
	return dist;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	memset(isVisited, false, sizeof(isVisited));

	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (int i = 0; i < picture.size(); i++) {
		for (int j = 0; j < picture[i].size(); j++) {
			if (!isVisited[i][j] && picture[i][j] != 0) {
				que.push({ i,j });
				isVisited[i][j] = true;
				max_size_of_one_area = max(max_size_of_one_area, setMove(picture, number_of_area, m, n));
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}