#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else if (a < b) {
		long long temp = a;
		a = b;
		b = temp;
	}
	return gcd(b, a%b);
}

int main() {
	long long a, b;
	cin >> a >> b;
	long long GCD = gcd(a, b);
	for (long long i = 0; i < GCD; ++i) {
		printf("1");
	}
}


