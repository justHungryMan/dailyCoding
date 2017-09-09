#include <cstdio>
#include <cstdbool>
int n, m;
int r, c, d;
int board[51][51] = {0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool fin = false;

int printAns() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0 ; j < m; ++j) {
            if (board[i][j] == 2) {
                ans += 1;
            }
        }
    }
    return ans;
}

int checkFin(int x, int y, int direction) {
    if (board[x][y] == 1) return printAns();
    return -1;
}

int func(int x, int y, int direction) {
    int ans = checkFin(x, y, direction);
    if (ans != -1) return ans;
    for (int i = 0; i < 4 && fin == false; ++i) {	// 4.1, 4.2, 4.3
        int nextDirection = (direction + 3 - i) % 4;
        int nextX = x + dx[nextDirection];
        int nextY = y + dy[nextDirection];
        if (nextX >= 0 && nextY >= 0 && board[nextX][nextY] == 0 ) {
            board[nextX][nextY] = 2;
            return func(nextX, nextY, nextDirection);
        }
    }
    return func(x + dx[(direction + 2) % 4], y + dy[(direction + 2) % 4], direction);
};

int main() {
    
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &board[i][j]);
        }
    }
    board[r][c] = 2;
    printf("%d\n", func(r, c, d));
}
