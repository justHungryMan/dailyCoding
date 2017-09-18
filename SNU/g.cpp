#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int seat[200001];
int n, m;
void query(int x) {
    seat[x] = 0;
    if (x < n / 2) {
        for (int i = x; i < n / 2; ++i) {
            seat[i] = seat[i + 1];
            seat[i + 1] = 0;
        }
    }
    else if (x > n / 2) {
        for (int i = x; i > n / 2; --i) {
            seat[i] = seat[i - 1];
            seat[i - 1] = 0;
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        seat[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 2) printf("%d\n", seat[b]);
        else query(b);
    }

}
