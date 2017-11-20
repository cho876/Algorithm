#pragma once
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Neighbors;

class Graph {
public:
	Graph(int vn);
	~Graph();
	void AddEdge(int start, int goal);
	void ViewNeighbors() const;
	void ViewNeighbor(int vt) const;
	Neighbors FindNeighbor(int vt); 

private:
	const int vn;
	int** matrix; 
};