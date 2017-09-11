#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int t[17];
int p[17];
int dp[17] = {0, };
int answer(int day) {
    int ans = 0;
    if (day > n) return 0;
    for (int i = day; i <= n; ++i) {
        if (i + t[i] - 1 <= n)
            ans = max(ans, answer(i + t[i]) + p[i]);
    }
    return ans;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &t[i], &p[i]);
    }
    printf("%d\n", answer(1));
}
