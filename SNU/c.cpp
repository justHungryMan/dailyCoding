#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n;
int map[1001][1001] = {0,};
int newMap[1001][1001] = {0,};
string input;

void swap(int x, int y) {
    newMap[x][y] = 1 - newMap[x][y];

    for (int i = 0; i < 4; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX >= 0 && nextY >= 0 && nextX <= n && nextY <= n) {
            newMap[nextX][nextY] = 1 - newMap[nextX][nextY];
        }
    }
}

void print(){
    for (int i = 0; i < n; ++i) {
        for (int j = 0 ; j < n; ++j) {
            printf("%d ", newMap[i][j]);
        }
        puts("");
    }
    puts("");
}

int main() {
    scanf("%d", &n);
    cin >> input;
    for (int i = 0; i < n; ++i) {
        if (input[i] == '.') map[0][i] = 0;
        else map[0][i] = 1;
        newMap[0][i] = map[0][i];
    }

    for (int i = 0; i < n; ++i) {
        if (map[0][i] == 1) {
            swap(0, i);
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (newMap[i - 1][j] == 1) {
                map[i][j] = 1;

                newMap[i][j] = 1 - newMap[i][j];
            }
        }
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == 1) {
                swap(i, j);
            }
        }
       // print();
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == 0) printf("%c", '.');
            else printf("%c", '#');
        }
        puts("");
    }
}
