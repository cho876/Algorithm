#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int testCase;
	scanf("%d", &testCase);

	int inputData;
	for (int i = 0; i < testCase; i++) {
		scanf("%d", &inputData);
		vector<int> v_num(inputData + 1);
		
		v_num[0] = 0;
		v_num[1] = 1;
		v_num[2] = 2;
		v_num[3] = 4;

		if (inputData > 3) {
			for (int i = 4; i <= inputData; i++) 
				v_num[i] = v_num[i - 3] + v_num[i - 2] + v_num[i - 1];
		}
		printf("%d\n", v_num[inputData]);
	}
	return 0;
}