/**
	Test Case

	3
	10
	Jeju Pangyo Seoul NewYork LA Jeju Pangyo Seoul NewYork La
	3
	9
	Jeju Pangyo Seoul Jeju Pangyo Seoul Jeju Pangyo Seoul
	2
	12
	Jeju Pangyo Seoul NewYork LA SanFrancisco Seoul Rome Paris Jeju NewYork Rome
	5
	12
	Jeju Pangyo Seoul NewYork LA SanFrancisco Seoul Rome Paris Jeju NewYork Rome
	2
	4
	Jeju Pangyo NewYork newyork
	0
	5
	Jeju Pangyo Seoul NewYork LA
*/
#include <iostream>
#include <cstdio>
#include <deque>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int cmpStr(deque<string> deq, string str) {
	int pos = -1;
	for (int i = 0; i < deq.size(); i++) 
		if (deq[i] == str) 
			pos = i;

	return pos;
}

int main() {
	int tc = 6;
	while (tc--) {
		int res = 0;

		int cacheSize;
		scanf("%d", &cacheSize);

		int citiCnt;
		scanf("%d", &citiCnt);

		vector<string> cities;
		string city;
		for (int i = 0; i < citiCnt; i++) {
			cin >> city;
			cities.push_back(city);
		}

		deque<string> deq;
		for (int i = 0; i < cities.size(); i++) {
			transform(cities[i].begin(), cities[i].end(), cities[i].begin(), toupper);

			int pos = cmpStr(deq, cities[i]);

			// 캐시에 값이 존재하지 않을 경우
			if (pos < 0) {
				deq.push_back(cities[i]);
				if (deq.size() > cacheSize) 
					deq.pop_front();

				res += 5;
			}

			// 캐시에 값이 존재할 경우
			else if (pos >= 0) {
				for (int i = pos; i < deq.size() - 1; i++)
					deq[i] = deq[i + 1];

				deq[deq.size()-1] = cities[i];
				res += 1;
			}
		}
		printf("ans: %d\n", res);
	}
}