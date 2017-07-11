#include <iostream>
using namespace std;

int main() {
	int n;
	long long arr[100001];
	long long dynamic[100001] = {0};
	long long ans = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		dynamic[i] = arr[i];
	}

	for (int i = 1; i < n; ++i) {
		dynamic[i] = dynamic[i] < dynamic[i - 1] + arr[i] ? dynamic[i - 1] + arr[i] : dynamic[i];
	}
	ans = dynamic[0];
	for (int i = 0; i < n; ++i) {
		ans = ans < dynamic[i] ? dynamic[i] : ans;
	}
	cout << ans;
}
