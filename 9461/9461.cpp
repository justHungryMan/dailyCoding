#include <iostream>
using namespace std;

long long arr[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

long long f(int n) {
	if (arr[n] != 0) return arr[n];
	arr[n] = f(n - 1) + f(n - 5);
	return arr[n];
}

int main() {
	int n;
	int input;
	cin >> n;
	while (n--) {
		cin >> input;
		cout << f(input) << endl;;
	}
}
