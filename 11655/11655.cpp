#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	getline(cin, input);

	for (int i = 0; i < input.length(); ++i) {
		if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
			if ((input[i] <= 'Z' && input[i] >= 'N') || (input[i] <= 'z' &&input[i] >= 'n')) {
				input[i] -= 13;
			}
			else input[i] += 13;
		}

	}
	cout << input;
}

