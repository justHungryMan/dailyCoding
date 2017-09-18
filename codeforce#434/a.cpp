#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int t = pow(10, b);
	int i = 0;
	if (a % 10 == 3 || a % 10 == 7 || a % 10 == 1 || a % 10 == 9) {
		cout << a;
		for (int i = 0; i < b; ++i) {
			cout << '0';
		}
	}
	else while(++i) {
		long long p = a * i;
		if (p % t == 0) {
			cout << p;
			break;
		}
	}
}
