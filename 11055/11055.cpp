#include <iostream>
using namespace std;

int main() {
	int n;
	int dynamic[1001];
	int arr[1001];
	int ans = 0;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		dynamic[i] = arr[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j] && dynamic[i] <= arr[i] + dynamic[j]) {
				dynamic[i] = dynamic[j] + arr[i];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		ans = ans > dynamic[i] ? ans : dynamic[i];
	}
	cout << ans;
}

