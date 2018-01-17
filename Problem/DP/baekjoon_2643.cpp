#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp_sort(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first)
		return p1.second > p2.second;

	return p1.first > p2.first;
}

int main()
{
	int papers;
	scanf("%d", &papers);

	vector<pair<int, int> > v_paper;
	v_paper.resize(papers);
	vector<int> v_result;
	v_result.resize(papers);

	int row, col;
	for (int i = 0; i < papers; i++) {
		scanf("%d%d", &row, &col);
		v_paper[i].first = max(row, col);
		v_paper[i].second = min(row, col);
	}

	sort(v_paper.begin(), v_paper.end(), cmp_sort);

	int ans = -99999;
	
	for (int i = 0; i < v_result.size(); i++) {    // Base
		for (int j = 0; j < i; j++) {
			if (v_paper[i].first <= v_paper[j].first && v_paper[i].second <= v_paper[j].second) 
				v_result[i] = max(v_result[i], v_result[j]);
		}
		v_result[i]++;
		ans = max(ans, v_result[i]);
	}

	printf("%d\n", ans);

	return 0;
}