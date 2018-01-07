#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool isHappy(int num);
int getSum(int num);

int main()
{
	string num;
	cin >> num;


	int stringToInt = atoi(num.c_str());

	if (!isHappy(stringToInt))
		cout << "UNHAPPY" << endl;
	else
		cout << "HAPPY" << endl;

	return 0;
}

/**
	Function to determine if HAPPY

	param 1: The number you want to check for HAPPY
*/
bool isHappy(int num) {

	if (num == 4)
		return false;
	else if (num == 1)
		return true;

	else {
		int powNum = getSum(num);
		return isHappy(powNum);
	}
}

/**
	Function to obtain each square of squares

	param 1: The number to which you want to square the number of digits
*/
int getSum(int num) {
	int result = 0;
	int tmp;

	string s_num = to_string(num);
	for (int i = 0; i < s_num.length(); i++) {
		tmp = (s_num[i] - 48);
		result += pow(tmp, 2);
	}
	return result;
}