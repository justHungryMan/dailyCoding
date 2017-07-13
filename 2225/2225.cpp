#include <iostream>
using namespace std;

const int mod = 1000000000;
int arr[201][201] = {0};

int f(int n, int k) {
//	cout << "n : " << n << endl << "k : " << k << endl;
	if (arr[n][k] != 0) return arr[n][k];
	if (k==0) return 0;
	for (int i = 0; i <= n; ++i) {
		arr[n][k] += (f(n - i, k - 1) + 1) % mod;
	}
//	cout << "arr[" << n << "][" << k << "] : " << arr[n][k] << endl;
	return arr[n][k];
}

int main() {
	int n, k;
	cin >> n >> k;	
	cout << f(n, k - 1);
}
