#include <cstdio>
#include <algorithm>
#include <cstdbool>
#include <queue>
using namespace std;

int n, m;
int board[9][9];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int bfs() {
    int vBoard[9][9];
    bool vCheckBoard[9][9] = {false, };
    int ans = 0;
    queue < pair < int, int > > q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vBoard[i][j] = board[i][j];
            if (vBoard[i][j] != 0) vCheckBoard[i][j] = true;
            if (vBoard[i][j] == 2) q.push(make_pair(i, j));
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nextX = x + dx[k];
            int nextY = y + dy[k];
            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && vBoard[nextX][nextY] == 0 && vCheckBoard[nextX][nextY] == false) {
                vBoard[nextX][nextY] = 2;
                vCheckBoard[nextX][nextY] = true;
                q.push(make_pair(nextX, nextY));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0 ; j <m ;++j) {
            if (vBoard[i][j] == 0) ans += 1;
        }
    }
    return ans;
}
int ans() {
    int ans = 0;
    for (int i = 0; i < n * m; ++i) {
        if (board[i / m][i % m] != 0) continue;
        board[i / m][i % m] = 1;
        for (int j = i + 1; j < n * m; ++j) {
            if (board[j / m][j % m] != 0) continue;
            board[j / m][j % m] = 1;
            for (int k = j + 1; k < n * m; ++k) {
                if (board[k / m][k % m] != 0) continue;
                board[k / m][k % m] = 1;
                ans = max(ans, bfs());
                board[k / m][k % m] = 0;
            }
            board[j / m][j % m] = 0;
        }
        board[i / m][i % m] = 0;
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0 ; j < m; ++j) {
            scanf("%d", &board[i][j]);
        }
    }
    printf("%d\n", ans());
}
