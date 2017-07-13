#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	int arr[26] = {0};

	cin >> input;

	for (int i = 0; i < input.length(); ++i) {
		arr[input[i] - 97] += 1;
	}
	for (int i = 0; i < 26; ++i) {
		cout << arr[i] << ' ';
	}
}
