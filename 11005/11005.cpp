#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string itos(int m) {
	string temp;
	if (m >= 0 && m <= 9) {
		temp += '0' + m;
	}
	else {
		temp += 'A' + m - 10;
	}
	return temp;
}

int main() {
	int n, t;
	string ans;
	cin >> n >> t;	
	while (n) {
		ans += itos(n % t);
		n /= t;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;

}
