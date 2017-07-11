#include <iostream>
#include <algorithm>
using namespace std;

int price[1001] = {0};
int profit[1001] = {0};

int dynamic(int n) {
	if (profit[n] != 0) {
		return profit[n];
	}
	for (int i = 1; i <= n; ++i) {
	 	profit[n] = max(profit[n], dynamic(i - 1) + price[n + 1 - i]);
	}
	return profit[n];
}

int main() {
	int n;
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> price[i];
	}
	cout << dynamic(n);
}
