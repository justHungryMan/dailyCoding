#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int arr[301];
	int f[301][3];

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	f[0][2] = 0;
	f[0][1] = arr[0];
	f[0][0] = 0;	
	for (int i = 1; i < n; ++i) {
		f[i][0] = max(f[i - 1][1], f[i - 1][2]);
		f[i][1] = f[i - 1][0] + arr[i];
		f[i][2] = f[i - 1][1] + arr[i];
	}
	cout << max(f[n - 1][1], f[n - 1][2]);
}
