#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool DFS(vector<int>* v_adj, int cow_index);

bool isVisited[200];
int arr_cow[200];
int arr_room[200];

int main() {
	int cow, room;
	scanf("%d%d", &cow, &room);
	vector<int>* v_adj = new vector<int>[cow];

	int wants;
	int room_index;

	for (int i = 0; i < cow; i++) {
		scanf("%d", &wants);
		for (int j = 0; j < wants; j++) {
			scanf("%d", &room_index);
			v_adj[i].push_back(room_index - 1);
		}
	}

	fill(arr_cow, arr_cow + cow, -1);
	fill(arr_room, arr_room + room, -1);

	int count = 0;
	for (int i = 0; i < cow; i++) {
		fill(isVisited, isVisited + cow, false);
		if (DFS(v_adj, i))
			count++;
	}

	printf("%d\n", count);

	return 0;
}

bool DFS(vector<int>* v_adj, int cow_index) {
	if (isVisited[cow_index])
		return false;
	else {
		isVisited[cow_index] = true;

		int room_index;
		for (int i = 0; i < v_adj[cow_index].size(); i++) {
			room_index = v_adj[cow_index][i];

			if (arr_room[room_index] == -1 || DFS(v_adj, arr_room[room_index])) {
				arr_room[room_index] = cow_index;
				arr_cow[cow_index] = room_index;

				return true;
			}
		}
	}
	return false;
}