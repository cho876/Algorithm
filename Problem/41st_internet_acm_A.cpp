/**
	The 41st Annual ACM
		Asia Regional-Daejeon
		Nationwide Internet Competition
		Probelm A (Binary truee)
*/

#include <iostream>
#include <math.h>

using namespace std;


struct Node {
	int value;
	int leftSum;
};

int main()
{
	int max = 0;   // Sum of node's values

	int height;
	cin >> height;
	int total_nodes = pow(2, height + 1) - 2 + 1;  // Total number of nodes

	Node* node = new Node[total_nodes];
	node[0].value = 0;
	node[0].leftSum = 0;

	for (int i = 1; i < total_nodes; i++) {  // Enter a value for each node
		cin >> node[i].value;
		node[i].leftSum = 0;
	}

	for (int i = (total_nodes - 1); i > 0; i = i - 2) {
		if (i >= total_nodes / 2) {   // If the nodes are the lowermost nodes
			if (node[i].value != node[i - 1].value) {   // If the two values are different, the larger number is matched.
				if (node[i].value > node[i - 1].value)
					node[i - 1].value = node[i].value;
				else
					node[i].value = node[i - 1].value;
			}
			node[(i - 1) / 2].leftSum = node[i - 1].value;
		}
		else {    // If the nodes are other than the lowermost node
			int left = node[i - 1].value + node[i - 1].leftSum;
			int right = node[i].value + node[i].leftSum;
			if (right != left) {  // If the two values are different, the value of the current node and the sum of the previous nodes are matched to the larger one.
				if (right > left)
					node[i - 1].value = (node[i].value + node[i].leftSum) - node[i - 1].leftSum;
				else
					node[i].value = (node[i - 1].value + node[i - 1].leftSum) - node[i].leftSum;
			}
			node[(i - 1) / 2].leftSum = node[i - 1].value + node[i - 1].leftSum;
		}
		max += node[i].value;
		max += node[i - 1].value;
	}
	cout << max << endl;
	return 0;
}