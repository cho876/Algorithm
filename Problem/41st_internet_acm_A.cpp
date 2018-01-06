#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Node {
	int left_weight;
	int right_weight;
};

int recurCount(Node* tree, int index, int limit, int& sum);

int main()
{
	int height;
	cin >> height;

	int total_nodes = pow(2, height + 1) - 1;
	int limit = total_nodes / 2;

	Node* arr_node = new Node[limit];

	Node node;
	int tmp_left, tmp_right;
	for (int i = 0; i < limit; i++){
		cin >> tmp_left >> tmp_right;
		node.left_weight = tmp_left;
		node.right_weight = tmp_right;
		arr_node[i] = node;
	}
	
	int sum = 0;

	recurCount(arr_node, 0, (limit/2), sum);
	cout << sum << endl;
}

int recurCount(Node* tree, int index, int limit, int& sum) {
	if (index >= limit) {
		if (tree[index].left_weight > tree[index].right_weight) {
			sum += (tree[index].left_weight * 2);
			return tree[index].left_weight;
		}
		else {
			sum += (tree[index].right_weight * 2);
			return tree[index].right_weight;
		}
	}
	else {
		int left_node = (2 * index) + 1;
		int right_node = left_node + 1;

		int left_max = recurCount(tree, left_node, limit, sum);
		int right_max = recurCount(tree, right_node, limit, sum);

		if (left_max + tree[index].left_weight > right_max + tree[index].right_weight) {
			tree[index].right_weight = left_max + tree[index].left_weight - right_max;
			sum += (tree[index].left_weight + tree[index].right_weight);

			return left_max + tree[index].left_weight;
		}
		else {
			tree[index].left_weight = right_max + tree[index].right_weight - left_max;
			sum += (tree[index].left_weight + tree[index].right_weight);

			return right_max + tree[index].right_weight;
		}
	}
}