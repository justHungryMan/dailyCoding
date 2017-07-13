#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int arr[100001];

int f(int n) {
	if (arr[n] != INT_MAX) {
		return arr[n];
	}
	for (int i = 1; i * i <= n; ++i) {
		arr[n] = min(arr[n], f(n - i * i) + 1);
	}
	return arr[n];
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i <= n; ++i) {
		arr[i] = INT_MAX;
	}
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 1;
	arr[5] = 2;
	arr[6] = 3;
	cout << f(n);
}
