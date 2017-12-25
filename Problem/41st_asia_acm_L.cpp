/**
	The 41st Annual ACM
		Asia Regional-Daejeon
		ASIA Regional
		Probelm L (Virus)
*/

#include <iostream>

using namespace std;

struct Node {
	int index;
	Node* leftNode;
	Node* rightNode;
};

int count_nodes(Node* tree);  // Number of nodes Returned function

int main()
{
	int total_nodes;
	cin >> total_nodes;

	Node* tree = new Node[total_nodes];
	tree[0].index = 0;
	for (int i = 0; i < total_nodes; i++) {
		tree[i].leftNode = NULL;
		tree[i].rightNode = NULL;
	}

	Node* target = &tree[0];
	int left, right = 0;
	int index = 1;  // Incremental indexes based on user input

	for (int i = 0; i < total_nodes; i++) {
		cin >> left >> right;

		if (left != 0) {
			tree[index].index = left;
			target->leftNode = &tree[index++];  // If you enter a non-zero value, the current node is stored in the left node of the target node.
		}
		if (right != 0) {
			tree[index].index = right;
			target->rightNode = &tree[index++];  // If you enter a non-zero value, the current node is stored in the right node of the target node.
		}
	}

	int result = 1;   // Number of infected nodes
	Node* curNode = &tree[0];  // Current node
	while (curNode != NULL) {
		if (count_nodes(curNode->leftNode) == 0 || count_nodes(curNode->rightNode) == 0)  // If there is a node with zero child nodes, it stops.
			break;
		if (count_nodes(curNode->leftNode) > count_nodes(curNode->rightNode))  // If the total number of nodes in the left node is greater than the total number of nodes in the right node,
			curNode = tree[0].rightNode;									   //the right node is infected.
		else if (count_nodes(curNode->leftNode) <= count_nodes(curNode->rightNode))
			curNode = tree[0].leftNode;
		result++;
	}
	cout << result << endl;
}

int count_nodes(Node* tree) {
	int count = 0;
	if (tree != NULL)
		count = 1 + count_nodes(tree->leftNode) + count_nodes(tree->rightNode);
	return count;
}