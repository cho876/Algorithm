#include "Graph.h"

int main()
{
	
	int total_node, total_edge;
	int start, goal;

	cin >> total_node >> total_edge;

	Graph* graph = new Graph(total_node);

	for (int i = 0; i < total_edge; i++) {
		cin >> start >> goal;
		graph->AddEdge(start, goal);
	}

	graph->ViewNeighbors();

	return 0;
}