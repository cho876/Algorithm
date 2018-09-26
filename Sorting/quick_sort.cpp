#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

/**
	수행시간 O(NlogN)
*/
void quick_sort(int left, int right, vector<int>& data) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;

	if (left < right) {
		for (i; i <= right; i++) {
			if (data[i] < data[pivot]) {
				j++;
				swap(data[i], data[j]);
			}
		}
		swap(data[left], data[j]);
		pivot = j;

		quick_sort(left, pivot - 1, data);
		quick_sort(pivot+1, right, data);
	}
}

int main() {
	int cnt;
	scanf("%d", &cnt);

	int value;
	vector<int> data;
	for (int i = 0; i < cnt; i++) {
		scanf("%d", &value);
		data.push_back(value);
	}

	quick_sort(0, data.size() - 1, data);
	for (int num : data)
		printf("%d ", num);
	printf("\n");
}