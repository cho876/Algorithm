#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int solution(int X, int Y, int D) {
int res;

res = (abs(Y - X) % D == 0 ? abs(Y - X) / D : abs(Y - X) / D + 1);

return res;
}

int main() {
int res = solution(10, 85, 30);

return 0;
}