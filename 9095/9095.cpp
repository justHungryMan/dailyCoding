#include <iostream>

unsigned int arr[13] = {0, 1, 2, 4};

int dynamic(int n) {
	if (arr[n] == 0 && n >= 4) {
		arr[n] = dynamic(n-1) + dynamic(n-2) + dynamic(n-3);
	}
	return arr[n];
}

int main() {
	using namespace std;

	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		cout << dynamic(k) << endl;
	}
}
