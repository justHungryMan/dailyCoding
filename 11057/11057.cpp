#include <iostream>
using namespace std;

int arr[1001][10];
const int mod = 10007;

int main() {
	int n;
	int result = 0;

	for (int i = 0; i < 10; ++i) {
		arr[1][i] = 1;
	}

	cin >> n;
	
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k <= j; ++k) {
				arr[i][j] += arr[i - 1][k] % mod;
				arr[i][j] = arr[i][j] % mod;
			}
		}
	}
	
	for (int i = 0; i < 10; ++i) {
		result += arr[n][i];
		result = result % mod;
	}
	cout << result;
}
