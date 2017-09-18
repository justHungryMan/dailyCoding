#include <cstdio>
#include <string>
#include <iostream>
#include <map> 
using namespace std;

int main() {
	string ok = "Wa-pa-pa-pa-pa-pa-pow!";
	string no = "Woof-meow-tweet-squeek";
	map <int, int> s;
	int n;
	int a, b;
	bool f = false, se = false, t = false;
	bool f1 = true;
	scanf("%d", &n);
	for (int i = 1; i <= 5; ++i) {
		s[i] = false;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);
		if (a == 2 || b == 2 || a == 5 || b == 5) f1 = false;
		else if (a * b == 3) f = true;
		else if (a * b == 4) se = true;
		else if (a * b == 12) t = true;
	}
	if (f && se && t && f1) cout << ok;
	else cout << no;
}
