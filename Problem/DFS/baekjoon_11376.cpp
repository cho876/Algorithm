#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool DFS(vector<int>* v_adj, bool*& isVisited, int*& arr_man, int*& arr_work, int local_man);

int main()
{
	int employee, work;
	scanf("%d%d", &employee, &work);
	vector<int>* v_adj = new vector<int>[employee];
	
	int wants;
	int tmp_work;
	for (int i = 0; i < employee; i++) {
		scanf("%d", &wants);
		for (int j = 0; j < wants; j++) {
			scanf("%d", &tmp_work);
			v_adj[i].push_back(tmp_work - 1);
		}
	}

	bool* isVisited = new bool[employee];
	int* arr_man = new int[employee];
	int* arr_work = new int[work];

	fill(arr_man, arr_man + employee, -1);
	fill(arr_work, arr_work + work, -1);

	int count = 0;
	for (int i = 0; i < employee; i++) {
		for (int j = 0; j < 2; j++) {
			fill(isVisited, isVisited + employee, false);
			if (DFS(v_adj, isVisited, arr_man, arr_work, i))
				count++;
		}
	}

	printf("%d\n", count);

	return 0;
}

bool DFS(vector<int>* v_adj, bool*& isVisited, int*& arr_man, int*& arr_work, int local_man) {
	if (isVisited[local_man])
		return false;
	else {
		isVisited[local_man] = true;

		int local_work;
		for (int i = 0; i < v_adj[local_man].size(); i++) {
			local_work = v_adj[local_man][i];

			if (arr_work[local_work] == -1 || DFS(v_adj, isVisited, arr_man, arr_work, arr_work[local_work])) {
				arr_work[local_work] = local_man;
				arr_man[local_man] = local_work;

				return true;
			}
		}
	}
	return false;
}