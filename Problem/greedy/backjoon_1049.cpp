#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Brand {
	int package;
	int single;
};

bool cmp_sort(Brand a, Brand b) { return a.single < b.single; }

int main() {
	int lines;
	int type;
	cin >> lines >> type;
	vector<Brand> v_brand;

	Brand brand;
	for (int i = 0; i < type; i++) {
		cin >> brand.package >> brand.single;
		v_brand.push_back(brand);
	}

	sort(v_brand.begin(), v_brand.end(), cmp_sort);

	int package_choice = 9999999;
	for (int i = 0; i < type; i++) 
		package_choice = min(v_brand[i].package, package_choice);

	package_choice = min(v_brand[0].single * 6, package_choice);

	int result = 0;
	result = package_choice * (lines / 6);
	lines %= 6;

	if (v_brand[0].single * lines > package_choice)  
		result += package_choice;
	else 
		result += v_brand[0].single * lines;

	cout << result << endl;
}