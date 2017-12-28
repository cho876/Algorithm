#include "Graph.h"


Graph::Graph(int vn) :vn(vn) 
{
	matrix = new int*[vn];

	for (int i = 0; i < vn; i++) {
		matrix[i] = new int[vn];
		memset(matrix[i], 0, sizeof(int)*vn);
	}
}

Graph::~Graph() 
{
	for (int i = 0; i < vn; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void Graph::AddEdge(int start, int goal)
{
	matrix[start][goal] = 1;
	matrix[goal][start] = 1;
}

void Graph::ViewNeighbors() const
{
	cout << "===== ÀÌ¿ô ¸ñ·Ï =====" << endl;

	for (int i = 0; i < vn; i++) {
		cout << i << "ÀÇ ÀÌ¿ô ¸ñ·Ï: ";
		ViewNeighbor(i);
	}
}

void Graph::ViewNeighbor(int vt) const
{
	for (int i = 0; i < vn; i++) {
		if (matrix[i][vt] == 1)
			cout << i << " ";
	}
	cout << endl;
}

Neighbors Graph::FindNeighbor(int vt)
{
	Neighbors neighbors;
	for (int i = 0; i < vn; i++) {
		if (matrix[i][vt] == 1)
			neighbors.push_back(i);
	}
	return neighbors;
}