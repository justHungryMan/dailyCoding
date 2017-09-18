#include <cstdio>
#include <iostream>
using namespace std;

int a, b;

char answer() {
	int ta = 0, tb = 0;
	for (int i = 0; i < 1440; i += 2) {
		ta += 1;
		ta = ta % 360;
		tb += 12;
		tb = tb % 360;

		if (ta == a && tb == b) return 'O';
	}
	return 'X';
}

int main() {
	cin >> a >> b;
	cout << answer();	
}
