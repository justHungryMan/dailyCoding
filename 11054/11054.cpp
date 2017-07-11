#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	vector <int> dynamicRev;
	int dynamic[1001];
	vector <int> arrRev;
	int arr[1001];
	int ans = 0;

	cin >> n;
	arrRev.resize(n);
	dynamicRev.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> arrRev[i];
		arr[i] = arrRev[i];
		dynamic[i] = dynamicRev[i] = 1;
	}
	reverse(arrRev.begin(), arrRev.end());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arrRev[i] > arrRev[j] && dynamicRev[i] <= dynamicRev[j]) {
				dynamicRev[i] = dynamicRev[j] + 1;
			}
			if (arr[i] > arr[j] && dynamic[i] <= dynamic[j]) {
				dynamic[i] = dynamic[j] + 1;
			}
		}
	}
	reverse(dynamicRev.begin(), dynamicRev.end());
	for (int i = 0; i < n; ++i) {
		ans = ans > dynamic[i] + dynamicRev[i] - 1 ? ans : dynamic[i] + dynamicRev[i] - 1;
	}
	cout << ans;
}

