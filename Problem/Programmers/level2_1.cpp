#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(int n) {
	string ans = "";

	vector<int> vec;

	while (n > 0) {
		int last = n % 3;
		n /= 3;

		if (last == 0)
			n--;

		vec.push_back(last);
	}

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 0)
			ans = "4" + ans;
		else
			ans = to_string(vec[i]) + ans;
	}
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	solution(n);
}