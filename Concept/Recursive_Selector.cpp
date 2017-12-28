/**
	Algorithm to find all combinations by superimposing all elements (Recursive Solution)

	¡Ø Prevent duplication
*/

#include <iostream>
#include <vector>

using namespace std;

void pick(int, vector<int>&, int);
void printPicked(vector<int>&);

int main()
{
	vector<int> v;

	int n;  // Total number of digits
	int m;  // Number of digits to choose
	cin >> n >> m;

	pick(n, v, m);
	return 0;
}

/**
	param 1: Total number of digits
	param 2: Space to store numbers
	param 3: Number of numbers still to choose
*/
void pick(int n, vector<int>& picked, int m) {
	if (m == 0) {
		printPicked(picked);
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, m - 1);
		picked.pop_back();
	}
}

void printPicked(vector<int>& picked) {
	vector<int>::iterator iter = picked.begin();
	for (iter; iter != picked.end(); iter++) {
		cout << *iter<<" ";
	}
	cout << endl;
}