#include <iostream>
#include <array>
using namespace std;

const unsigned char LEN = 26;

int main() {
	string input;
	array <int, LEN> arr;

	arr.fill(-1);
	cin >> input;
	
	for (int i = 0; i < input.length(); ++i) {
		if (arr[input[i] - 97] == -1) arr[input[i] - 97] = i;			
	}
	for (int i = 0; i < LEN; ++i) {
		cout << arr[i] << " ";
	}
}
