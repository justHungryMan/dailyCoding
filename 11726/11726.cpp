#include <iostream>
using namespace std;

int n;
const int MAX = 1001;
int arr[MAX] = {1, 1, 2};

int tile(int n) {
	if (arr[n] != 0) return arr[n];
	arr[n] = (tile(n - 1) % 10007 + tile(n - 2) % 10007) % 10007;
	return arr[n];		
}

int main() {
	cin >> n;
	cout << tile(n);	
}
