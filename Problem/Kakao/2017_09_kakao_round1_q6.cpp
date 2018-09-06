#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board){
	vector<vector<bool> > canRemove;
	canRemove.assign(m, vector<bool>(n, false));

	int tmp_Cnt = 0;
	int res_Cnt = 0;

	while (true) {
		tmp_Cnt = 0;

		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1]) {
					canRemove[i][j] = true;
					canRemove[i + 1][j] = true;
					canRemove[i][j + 1] = true;
					canRemove[i + 1][j + 1] = true;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (canRemove[i][j]) {
					board[i][j] = ' ';
					tmp_Cnt++;
				}
			}
		}

		if (!tmp_Cnt)
			break;

		res_Cnt += tmp_Cnt;

		while (true) {
			bool isMoved = false;
			for (int i = m - 1; i > 0; i--) {
				for (int j = 0; j < n; j++) {
					if (board[i][j] == ' ' && board[i - 1][j] != ' ') {
						board[i][j] = board[i - 1][j];
						board[i - 1][j] = ' ';
						isMoved = true;
					}
				}
			}
			if (!isMoved)
				break;
		}
	}
	return res_Cnt;
}