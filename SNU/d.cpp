#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int height[5001];
vector < int > v[5001];
int maxCount[5001] = {0,};
int answer(int start) {
    int Max = 1;
    if (maxCount[start] != 0) return maxCount[start];
    for (int i = 0; i < v[start].size(); ++i) {
        int next = v[start][i];
        Max = max(Max, answer(next) + 1);
        maxCount[start] = max(Max, maxCount[start]);
    }

    return Max;
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &height[i]);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (height[a] > height[b]) v[b].push_back(a);
        else v[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        cout << answer(i) << '\n';
    }

}
