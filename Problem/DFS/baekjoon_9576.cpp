#include <iostream>
#include <cstdio>
#include <vector>

#define NIL -1

using namespace std;

bool DFS(vector<int>* v_adj, int man, bool*& isVisited, int*& book);

int main()
{
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		int totalMan, totalBook;
		scanf("%d%d", &totalBook, &totalMan);
		vector<int>* v_adj = new vector<int>[totalMan];

		int from, to;
		for (int i = 0; i < totalMan; i++) {
			scanf("%d%d", &from, &to);
			for (int j = from - 1; j < to; j++)
				v_adj[i].push_back(j);
		}

		bool* isVisited = new bool[totalMan];
		int* book = new int[totalBook];
		fill(book, book + totalBook, NIL);


		int count = 0;
		for (int i = 0; i < totalMan; i++) {
			fill(isVisited, isVisited + totalMan, false);
			if (DFS(v_adj, i, isVisited, book))
				count++;
		}

		printf("%d\n", count);
	}
	return 0;
}

bool DFS(vector<int>* v_adj, int man, bool*& isVisited, int*& book) {
	if (!isVisited[man]) {
		isVisited[man] = true;

		int nextBook;
		for (int i = 0; i < v_adj[man].size(); i++) {
			nextBook = v_adj[man][i];
			if (book[nextBook] == NIL || DFS(v_adj, book[nextBook], isVisited, book)) {
				book[nextBook] = man;
				return true;
			}
		}
	}
	return false;
}