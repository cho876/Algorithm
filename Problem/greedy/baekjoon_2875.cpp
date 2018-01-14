#include <iostream>
#include <algorithm>

using namespace std;

int getWomanCount(int woman) {
	return woman/2;
}

int main() {
	int woman, man, intern;
	cin >> woman >> man >> intern;

	int womanCount;
	while (intern > 0) {
		womanCount = getWomanCount(woman);
		if (womanCount >= man)
			woman -= 1;
		else
			man -= 1;
		intern--;
	}

	cout << min(getWomanCount(woman), man) << endl;
}