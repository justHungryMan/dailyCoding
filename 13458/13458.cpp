#include <cstdio>

int main() {
	const int max = 1000000;
	int a[max];
	int n, b, c;
	long long ans = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%d %d", &b, &c);
	ans = n;
	for (int i = 0; i < n; ++i) {
		a[i] -= b;
		if (a[i] < 0) a[i] = 0;
		ans += a[i] / c;
		if (a[i] % c != 0) ans += 1;
	}
	printf("%lld\n", ans);
}
