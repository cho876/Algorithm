#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;


vector<int> solution(vector<int> &A, int K) {
vector<int> res(A.size());

for (int i = 0; i < A.size(); i++) {
res[(i + K) % A.size()] = A[i];
}

return res;
}

int main() {
vector<int> A = { 3,8,9,7,6 };

vector<int> res = solution(A, 3);
}