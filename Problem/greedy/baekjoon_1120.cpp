#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string cmp1;
	string cmp2;

	cin >> cmp1 >> cmp2;

	int count = 0;
	int result = 999999;
	for (int i = 0; i <= cmp2.length() - cmp1.length(); i++) {
		count = 0;
		for (int j = 0; j < cmp1.length(); j++) {
			if (cmp1[j] != cmp2[i + j])
				count++;
		}
		result = min(count, result);
	}

	cout << result << endl;

	return 0;
}