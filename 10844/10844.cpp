#include <iostream>
using namespace std;

int arr[101][10];
const int mod = 1000000000;
int main() {
	int n;
	int result = 0;
	for (int i = 1; i <= 9; ++i) {
		arr[1][i] = 1;
	}	// initiation

	cin >> n;
	
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j == 0) arr[i][0] = arr[i - 1][1] % mod;
			else if (j == 9) arr[i][9] = arr[i - 1][8] % mod;
			else {
				arr[i][j] = (arr[i - 1][j - 1] % mod + arr[i - 1][j + 1] % mod) % mod;
			}
		}
	}
	for (int i = 0; i < 10; ++i) {
		result = (result + arr[n][i]) % mod;
	}
	cout << result;
}
