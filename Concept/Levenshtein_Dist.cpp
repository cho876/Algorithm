/**
	Measure string similarity and find minimum edit distance
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void getMininum(int** arr, string& cmp1, string& cmp2);

int main()
{
	string cmp1, cmp2;
	cin >> cmp1 >> cmp2;

	int** arr = new int*[cmp1.length() + 1];

	for (int i = 0; i <= cmp1.length(); i++){
		arr[i] = new int[cmp2.length() + 1];
		arr[i][0] = i;
	}

	for (int i = 0; i <= cmp2.length(); i++)
		arr[0][i] = i;

	getMininum(arr, cmp1, cmp2);

	for (int i = 0; i <= cmp1.length(); i++) {
		for (int j = 0; j <= cmp2.length(); j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	cout << "Mininum: " << arr[cmp1.length()][cmp2.length()] << endl;
	return 0;
}

void getMininum(int** arr, string& cmp1, string& cmp2) {
	for (int i = 1; i <= cmp1.length(); i++) {
		for (int j = 1; j <= cmp2.length(); j++) {
			int cross = arr[i - 1][j - 1];

			if (cmp1[i - 1] == cmp2[j - 1]) // Pass diagonal values when characters are the same
				arr[i][j] = cross;
			
			else  // If the characters are different from each other, store the lowest value of +1 for the top, left, and diagonal values.
				arr[i][j] = min(cross + 1, min(arr[i - 1][j] + 1, arr[i][j - 1]+1));
		}
	}
}