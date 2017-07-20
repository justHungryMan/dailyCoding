#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
int main() {
	string s;
	int n;
	cin >> s >> n;
	
	int len = s.length();
	int pow = 1;
	ll res = 0;
	for (int i = 0; i < len; ++i) {
		if (i != 0) {
			pow *= n;
		}
		if (s[len - i - 1] >= '0' && s[len - i - 1] <= '9') {
			res += (s[len - i - 1] - 48) * pow;		
		}
		else {
			res += (s[len - i - 1] - 'A' + 10) * pow;
		}
	}
	cout << res;
}
