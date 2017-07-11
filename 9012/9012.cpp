#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.clear();
	while (n--) {
		stack <bool> s;
		string str;
		bool isFalse = false;
		cin >> str;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == '(') {
				s.push(true);
			}
			else {
				if (s.empty()) {
					isFalse = true;
					break;
				}
				else s.pop();
			}
		}
		if (isFalse || !s.empty()) {
			cout << "NO\n";
		}
		else cout << "YES\n";
	}
}
