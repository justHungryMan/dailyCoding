#include <iostream>
using namespace std;

int arr[31] = {1, 0, 3};

int f(int n) {
	if (arr[n] != 0) {
		return arr[n];
	}
	if (n >2) arr[n] += f(n - 2) * 3;
	for (int i = 4; i <= n; i += 2) {
		arr[n] += f(n - i) * 2;
	}
	return arr[n];
}

int main() {
	int n;
	cin >> n;
	cout << f(n);
}
