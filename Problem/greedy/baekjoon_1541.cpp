#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>

using namespace std;

int getSum(char* ptr);

int main()
{
	string str_oper;
	cin >> str_oper;

	char* c_oper = new char[str_oper.size() + 1];
	char* tmp_ptr = new char[str_oper.size() + 1];

	copy(str_oper.begin(), str_oper.end(), c_oper);

	char* ptr = strtok(c_oper, "-");
	strcpy(tmp_ptr, ptr);
	ptr = strtok(NULL, "");

	int leftSide = getSum(tmp_ptr);
	int rightSide = getSum(ptr);

	cout << leftSide - rightSide << endl;

	return 0;
}

int getSum(char* ptr) {
	int sum = 0;
	char* local_ptr = strtok(ptr, "+-");
	while (local_ptr != NULL) {
		sum += atoi(local_ptr);
		local_ptr = strtok(NULL, "+-");
	}
	return sum;
}