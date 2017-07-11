#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int dynamic[1001];
	vector <int> arr;
	int ans = 0;

	cin >> n;
	arr.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		dynamic[i] = 1;
	}
	reverse(arr.begin(), arr.end());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j] && dynamic[i] <= dynamic[j]) {
				dynamic[i] = dynamic[j] + 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		ans = ans > dynamic[i] ? ans : dynamic[i];
	}
	cout << ans;
}
