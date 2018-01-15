#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int ports;
	cin >> ports;

	vector<int> v_port;
	vector<int> v_result;

	int port;
	for (int i = 0; i < ports; i++) {
		cin >> port;
		v_port.push_back(port);
	}

	v_result.push_back(v_port[0]);
	int portNum = v_port[0];
	for (int i = 0; i < v_port.size(); i++) {
		if (portNum < v_port[i]) 
			v_result.push_back(v_port[i]);
		else {
			int iterNum = lower_bound(v_result.begin(), v_result.end(), v_port[i]) - v_result.begin();
			v_result[iterNum] = v_port[i];
		}
		portNum = v_result.back();
	}

	cout << v_result.size() << endl;
}