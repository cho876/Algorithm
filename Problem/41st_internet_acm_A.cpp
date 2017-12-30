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
	int leftChild;
	int rightChild;
	int leftWeight;
	int rightWeight;
};

int countRecur(Node* tree, int index, int &dist);

int main()
{
	int height;
	cin >> height;

	int total_nodes = pow(2, height + 1) - 1;  // Total number of nodes by height
	int parents = total_nodes / 2;  // The number of nodes that have all children

	Node* tree = new Node[parents];

	int lw, rw;
	for (int i = 0; i < parents; i++) {
		cin >> lw >> rw;
		tree[i].leftWeight = lw;
		tree[i].rightWeight = rw;
		
		int ln = (i * 2) + 1;
		int rn = ln + 1;
		if (ln>=parents) {  // 	When entering the lowest node, both child nodes are stored as 0
			tree[i].leftChild = 0;
			tree[i].rightChild = 0;
		}
		else {
			tree[i].leftChild = ln;
			tree[i].rightChild = rn;
		}
	}
	
	int dist = 0;
	cout << countRecur(tree, 0, dist) << endl;
	return 0;

}

/**
	Minimum sum return function through recursive method

*/
int countRecur(Node* tree, int index, int &dist)
{
	if (tree[index].leftChild == 0 && tree[index].rightChild == 0) {
		if (tree[index].leftWeight >= tree[index].rightWeight) {
			dist = tree[index].leftWeight;
			return tree[index].leftWeight * 2;
		}
		else {
			dist = tree[index].rightWeight;
			return tree[index].rightWeight * 2;
		}
	}
	else {
		int lChild = tree[index].leftChild;
		int rChild = tree[index].rightChild;

		int lDist = 0;
		int lweightSum = countRecur(tree, lChild, lDist) + tree[index].leftWeight;
		lDist += tree[index].leftWeight;
		
		int rDist = 0;
		int rweightSum = countRecur(tree, rChild, rDist) + tree[index].rightWeight;
		rDist += tree[index].rightWeight;
		
		int diff;
		if (lDist >= rDist) {
			diff = lDist - rDist;
			dist = lDist;
		}
		else {
			diff = rDist - lDist;
			dist = rDist;
		}
		return lweightSum + rweightSum + diff;
	}
}