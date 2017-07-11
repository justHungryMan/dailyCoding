#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string input;
	stack <bool> s;
	int result = 0;

	cin >> input;
	
	for (int i = 0; i < input.length(); ++i) {
		if (input[i] == '(') {
			s.push(true);
		}
		else {
			s.pop();
			if (input[i - 1] == '(') result += s.size();
			else result += 1; 
		}
	}
	cout << result;	
}
