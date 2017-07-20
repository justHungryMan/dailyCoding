#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	return gcd(b, a%b);
}

int main() {
	int a, b;
	int GCD;
	cin >> a >> b;
	GCD = gcd(a, b);
	cout << GCD << endl << a * b / GCD;
}
