#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string s;
	vector <string> v;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		v.push_back(s.substr(i, len));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
}
