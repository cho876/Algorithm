#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef struct {
	int idx;
	string head;
	string num;
}Node;

bool cmp(Node n1, Node n2) {
	transform(n1.head.begin(), n1.head.end(), n1.head.begin(), ::toupper);
	transform(n2.head.begin(), n2.head.end(), n2.head.begin(), ::toupper);

	if (n1.head == n2.head)
		return stoi(n1.num) < stoi(n2.num);

	return n1.head < n2.head;
}

vector<string> solution(vector<string> files) {
	vector<string> res;
	vector<Node> v_node;

	int pivot = 0;
	int idx = 0;
	for (string file : files) {
		Node node;
		pivot = 0;
		while (!(file[pivot] >= '0' && file[pivot] <= '9'))
			node.head += file[pivot++];
		while (file[pivot] >= '0' && file[pivot] <= '9')
			node.num += file[pivot++];

		node.idx = idx;
		v_node.push_back(node);
		idx++;
	}

	stable_sort(v_node.begin(), v_node.end(), cmp);

	for (int i = 0; i < v_node.size(); i++)
		res.push_back(files[v_node[i].idx]);

	return res;
}

int main() {
	vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
	vector<string> res = solution(files);
	
	for (string str : res)
		cout << str << endl;
	return 0;
}