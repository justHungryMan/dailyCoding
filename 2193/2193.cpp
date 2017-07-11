#include <iostream>
using namespace std;

long long arr[91][2];

long long dynamic(int n, int digit) {
	if (arr[n][digit] != 0 || n <= 2) {
		return arr[n][digit];
	}
	arr[n][0] = dynamic(n - 1, 0) + dynamic(n - 1, 1);
	arr[n][1] = dynamic(n - 1, 0);
	return arr[n][digit];
}

int main() {
	int n;
	
	arr[1][1] = 1;
	arr[2][0] = 1;
	arr[2][1] = 0;

	cin >> n;
	cout << dynamic(n, 0) + dynamic(n, 1);
}
