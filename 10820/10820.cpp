#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;

	while(getline(cin, input)) {
		int l = 0, c = 0 , n = 0, s = 0;
		for (int i = 0; i < input.length(); ++i) {
			if (input[i] == ' ') s += 1;
			else if (input[i] >= '0' && input[i] <= '9') n += 1;
			else if (input[i] >= 'a' && input[i] <= 'z') l += 1;
			else if (input[i] >= 'A' && input[i] <= 'Z')  c += 1;
		}
		cout << l << ' '<< c << ' ' << n << ' ' << s << endl;
	}
}
