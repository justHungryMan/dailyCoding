#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	string input;
	queue <int> q;
	int num;

	cin >> num;
	while (num--) {

		cin >> input;

		if (input == "push") {
			int n;
			cin >> n;
			q.push(n);
		}
		else if (input == "pop") {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (input == "size") {
			cout << q.size() << endl;
		}
		else if (input == "empty") {
			if (q.empty()) {
				cout << "1" << endl;
			}
			else cout << "0" << endl;
		}
		else if (input == "front") {
			if (q.empty()) cout << "-1" << endl;
			else cout << q.front() << endl;
		}
		else if (input == "back") {
			if (q.empty()) cout << "-1" << endl;
			else cout << q.back() << endl;
		}
	}
}

