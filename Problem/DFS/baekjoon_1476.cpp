#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int earth_total, sun_total, moon_total;
int ans;

void solution(int year, int earth, int sun, int moon) {
	while (earth != earth_total || sun != sun_total || moon != moon_total) {
		earth++; sun++; moon++;

		if (earth > 15)
			earth = 1;
		if (sun > 28)
			sun = 1;
		if (moon > 19)
			moon = 1;
		year++;
	}
	ans = year;
}

int main() {
	scanf("%d%d%d", &earth_total, &sun_total, &moon_total);
	solution(1, 1, 1, 1);
	printf("%d\n", ans);
}