#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	queue<pair<int,int> > q_list;

	int num;
	scanf("%d", &num);

	
	q_list.push(make_pair(num,0));

	int result = 0;

	while (!q_list.empty()) {
		int num = q_list.front().first;
		int count = q_list.front().second;
		q_list.pop();

		if (num == 1) {
			result = count;
			break;
		}

		if (num % 3 == 0)
			q_list.push(make_pair(num / 3, count + 1));

		if (num % 2 == 0)
			q_list.push(make_pair(num / 2, count + 1));

		q_list.push(make_pair(num - 1, count+1));
	}

	cout << result << endl;

	return 0;
}