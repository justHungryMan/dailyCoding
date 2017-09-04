#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

queue <string> q;
map <string, bool> m;
vector <int> v;
map <int, bool> answerSheet;
int a, b, c;

string toString(int a, int b, int c) {
	if (a == 0 && answerSheet[c] != true) {
		answerSheet[c] = true;
		v.push_back(c);
	}
	return to_string(a * 1000000 + b * 1000 + c);
}

void check(int A, int B, int C) {
	string temp = toString(A, B, C);
	if (m[temp] != true) {
		m[temp] = true;
		q.push(temp);
	}
}
void thirdToFirst(int A, int B, int C) {
	if (A + C > a) {
		C = A + C - a;
		A = a;
	}
	else {
		A = A + C;
		C = 0;
	}
	check(A, B, C);
}

void thirdToSecond(int A, int B, int C) {
	if (B + C > b) {
		C = B + C - b;
		B = b;
	}
	else {
		B = B + C;
		C = 0;
	}
	check(A, B, C);
}

void secondToThird(int A, int B, int C) {
	if (B + C > c) {
		B = B + C - c;
		C = c;
	}
	else {
		C = B + C;
		B = 0;
	}
	check(A, B, C);
}

void secondToFirst(int A, int B, int C) {
	if (A + B > a) {
		B = A + B - c;
		A = a;
	}
	else {
		A = A + B;
		B = 0;
	}
	check(A, B, C);
}

void firstToSecond(int A, int B, int C) {
	if (A + B > b) {
		A = A + B - b;
		B = b;
	}
	else {
		B = A + B;
		A = 0;
	}
	check(A, B, C);
}

void firstToThird(int A, int B, int C) {
	if (A + C > c) {
		A = A + C - c;
		C = c;
	}
	else {
		C = A + C;
		A = 0;
	}
	check(A, B, C);
}

void func(int a, int b, int c) {
	q.push(toString(0, 0, c));
	
	while (!q.empty()) {
		string f = q.front();
		cout << f << endl;
		q.pop();
		m[f] = true;
		int A = stoi(f) / 1000000;
		int B = (stoi(f) / 1000) % 1000;
		int C = stoi(f) % 1000;
		thirdToFirst(A, B, C);
		thirdToSecond(A, B, C);
		secondToFirst(A, B, C);
		secondToThird(A, B, C);
		firstToSecond(A, B, C);
		firstToThird(A, B, C);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << ' ';	
	}
}

int main() {
	cin >> a >> b >> c;
	func(a, b, c);
}
