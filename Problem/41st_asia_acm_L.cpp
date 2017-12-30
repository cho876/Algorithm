/**
	The 41st Annual ACM
	Asia Regional-Daejeon
	ASIA Regional

	Probelm L (Virus)
*/

#include <iostream>

using namespace std;


struct Node {
	int left;
	int right;
};

int countRecur(Node* tree, int index); // Number of nodes Returned function

int main()
{
	int number_of_nodes;
	cin >> number_of_nodes;

	Node* tree = new Node[number_of_nodes + 1];

	for (int i = 1; i <= number_of_nodes; i++) {
		cin >> tree[i].left >> tree[i].right;
	}
	cout << countRecur(tree, 1) << endl;
}

int countRecur(Node* tree, int index) {
	if (tree[index].left == 0 || tree[index].right == 0) // If the value of any of the child nodes of the parent node is 0, return 1
		return 1;
	else {
		int leftCount = countRecur(tree, tree[index].left);
		int rightCount = countRecur(tree, tree[index].right);
		
		if (leftCount >= rightCount)  // By comparing the number of left and right nodes of the parent node, +1
			return rightCount + 1;
		else
			return leftCount + 1;
	}
}