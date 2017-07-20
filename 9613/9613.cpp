#include <iostream>
#include <cstdio>
using namespace std;
int arr[101];

int gcd(int a, int b) {
	if (b == 0) return a;
	else if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	return gcd(b, a%b);
}

int main() {
	int a, b;
	int n;
	cin >> n;
	while (n--) {
		int temp;
		int res = 0;
		cin >> temp;
		for (int i = 0; i < temp; ++i) {
			cin >> arr[i];
		}
		for (int i = 0; i < temp - 1; ++i) {
			for (int j = i + 1; j < temp; ++j) {
				res += gcd(arr[i], arr[j]);
			}
		}
		cout << res << endl;
	}
}



