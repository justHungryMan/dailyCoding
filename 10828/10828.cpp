#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n, m;
	string input;
	stack <int> s;

	cin >> n;
	while (n--) {
		cin >> input;
		if (input == "push") {
			cin >> m;
			s.push(m);
		} 
		else if (input == "top") {
			if (s.empty()) {
				cout << "-1\n";
			}
			else {
				cout << s.top() << '\n';
			}
		}
		else if (input == "size") {
			cout << s.size() << '\n';
		}
		else if (input == "pop") {
			if (s.empty()) {
				cout << "-1\n";
			}
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (input == "empty") {
			if (s.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
	}
}
