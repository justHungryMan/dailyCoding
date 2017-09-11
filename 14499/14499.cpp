#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int x, y;
int k;
int command[1001];
int map[21][21];
int dice[6] = {0, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void east() {
    int eastDice[6];
    eastDice[0] = dice[1];
    eastDice[1] = dice[5];
    eastDice[2] = dice[0];
    eastDice[3] = dice[3];
    eastDice[4] = dice[4];
    eastDice[5] = dice[2];
    for (int i = 0; i < 6; ++i) {
        dice[i] = eastDice[i];
    }
}

void west() {
    int westDice[6];
    westDice[0] = dice[2];
    westDice[1] = dice[0];
    westDice[2] = dice[5];
    westDice[3] = dice[3];
    westDice[4] = dice[4];
    westDice[5] = dice[1];
    for (int i = 0; i < 6; ++i) {
        dice[i] = westDice[i];
    }
}

void south() {
    int southDice[6];
    southDice[0] = dice[3];
    southDice[1] = dice[1];
    southDice[2] = dice[2];
    southDice[3] = dice[5];
    southDice[4] = dice[0];
    southDice[5] = dice[4];
    for (int i = 0; i < 6; ++i) {
        dice[i] = southDice[i];
    }
}

void north() {
    int northDice[6];
    northDice[0] = dice[4];
    northDice[1] = dice[1];
    northDice[2] = dice[2];
    northDice[3] = dice[0];
    northDice[4] = dice[5];
    northDice[5] = dice[3];
    for (int i = 0; i < 6; ++i) {
        dice[i] = northDice[i];
    }
}

void answer() {
    for (int i = 0; i < k; ++i) {
        int determinant = command[i] - 1;
        int nextX = x + dx[determinant];
        int nextY = y + dy[determinant];
        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
            x = nextX;
            y = nextY;
            switch (determinant) {
                case 0: east();
                    break;
                case 1: west();
                    break;
                case 2: north();
                    break;
                case 3: south();
                    break;
            }
            if (map[x][y] == 0) {
                map[x][y] = dice[5];
            }
            else {

                dice[5] = map[x][y];
                map[x][y] = 0;
            }
            printf("%d\n", dice[0]);
        }
    }
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d", &command[i]);
    }
    answer();
}
