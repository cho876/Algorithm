#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int length;
	scanf("%d", &length);
	vector<long> v_num(length+1);

	v_num[0] = 0;
	v_num[1] = 1;
	v_num[2] = 1;

	if (length > 2) {
		for (int i = 3; i <= length; i++)
			v_num[i] = v_num[i - 2] + v_num[i - 1];
	}
	printf("%ld\n", v_num[length]);

	return 0;
}