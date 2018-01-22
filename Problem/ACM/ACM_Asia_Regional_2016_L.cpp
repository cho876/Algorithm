#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct Node {
	int left_node;
	int right_node;
};

int recur(Node* v_tree, int index);

int main()
{
	int total_nodes;
	cin >> total_nodes;
	
	Node* tree = new Node[total_nodes];

	int tmp_left, tmp_right;
	for (int i = 0; i < total_nodes; i++) {
		cin >> tmp_left >> tmp_right;
		tree[i].left_node = tmp_left;
		tree[i].right_node = tmp_right;
	}

	cout << recur(tree, 0) << endl;
}


int recur(Node* tree, int index) {
	if (tree[index].left_node == 0 || tree[index].right_node == 0) {
		return 1;
	}
	else {
		int left_index = 2 * index + 1;
		int right_index = left_index + 1;
		
		int left_counter = 0;
		int right_counter = 0;
		int counter = 0;

		left_counter = 1 + recur(tree, left_index);
		right_counter = 1 + recur(tree, right_index);

		if (left_counter > right_counter)
			counter = right_counter;
		else
			counter = left_counter;

		return counter;
	}
}