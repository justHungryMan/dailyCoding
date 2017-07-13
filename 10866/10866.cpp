#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	string input;
	deque <int> q;
	int num;

	cin >> num;
	while (num--) {

		cin >> input;

		if (input == "push_front") {
			int n;
			cin >> n;
			q.push_front(n);
		}
		else if (input == "push_back") {
			int n;
			cin >> n;
			q.push_back(n);
		}
		else if (input == "pop_front") {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
				q.pop_front();
			}
		}
		else if (input == "pop_back") {
			if (q.empty()) cout << "-1" << endl;
			else {
				cout << q.back() << endl;
				q.pop_back();
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


