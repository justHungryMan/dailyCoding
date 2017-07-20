#include <iostream>
#include <string>
using namespace std;

int main() {
	string a1, a2, b1, b2;
	long long A, B;
	cin >> a1 >> a2 >> b1 >> b2;
	a1 += a2;
	b1 += b2;

	A = stoll(a1);
	B = stoll(b1);
	cout << A + B;
}
