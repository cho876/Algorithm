#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int root_index[100000];

int find(int index);
bool merge(int left, int right);

class Info {
public:
	int left;
	int right;
	int weight;

	Info(int left, int right, int weight) :left(left), right(right), weight(weight) {}
	bool operator< (const Info info) { return weight < info.weight; }
};
int main() {
	int nodes, edges;
	scanf("%d%d", &nodes, &edges);
	vector<Info> v_info;

	int left, right, weight;
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &left, &right, &weight);
		v_info.push_back(Info(left - 1, right - 1, weight));
	}

	sort(v_info.begin(), v_info.end());

	fill(root_index, root_index + nodes, -1);

	int sum = 0;
	for (int i = 0; i < v_info.size(); i++) {
		if (merge(v_info[i].left, v_info[i].right))
			sum += v_info[i].weight;
	}

	printf("%d\n", sum);
	return 0;
}

int find(int index) {
	if (root_index[index] == -1)
		return index;
	else
		return find(root_index[index]);
}

bool merge(int left, int right) {
	int left_index = find(left);
	int right_index = find(right);

	if (left_index == right_index)
		return false;

	root_index[right_index] = left_index;
	return true;
}