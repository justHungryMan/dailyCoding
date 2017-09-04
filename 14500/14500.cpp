#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int board[501][501];

int answer();
int do1();
int do2();

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &board[i][j]);
		}
	}
	cout << answer();
}

int answer() {
	return max(do1(), do2());
}

int do1() {
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m - 4; ++j) {
			int sum = 0;
			for (int k = j; k < j + 4; ++k) {
				sum += board[i][k];
			}
			ans = max(ans, sum);
		}
	}
	for (int i = 0; i <= n - 4; ++i) {
		for (int j = 0; j < m; ++j) {
			int sum = 0;
			for (int k = i; k < i + 4; ++k) {
				sum += board[k][j];
			}
			ans = max(ans, sum);
		}
	}
	return ans;
}

int do2() {
	int ans = 0;
	// 2 x 3
	for (int i = 0; i <= n - 3; ++i) {
		for (int j = 0; j <= m - 2; ++j) {
			int sum = 0;
			for (int k = i; k < i + 3; ++k) {
				for (int l = j; l < j + 2; ++l) {
					sum += board[k][l];
				}
			}
			/*
			00
			11
			11
			*/
			ans = max(sum - board[i][j] - board[i][j + 1], ans); 	
			/*
			01
			01
			11
			*/
			ans = max(sum - board[i][j] - board[i + 1][j], ans);
			/*
			10
			10
			11
			*/
			ans = max(sum - board[i][j + 1] - board[i + 1][j + 1], ans);
			/*
			11
			11
			00
			*/
			ans = max(sum - board[i + 2][j] - board[i + 2][j + 1], ans);
			/*
			11
			10
			10
			*/
			ans = max(sum - board[i + 1][j + 1] - board[i + 2][j + 1], ans);
			/*
			11
			01
			01
			*/
			ans = max(sum - board[i + 1][j] - board[i + 2][j], ans);
			/*
			10
			11
			01
			*/
			ans = max(sum - board[i][j + 1] - board[i + 2][j], ans);
			/*
			01
			11
			10
			*/
			ans = max(sum - board[i][j] - board[i + 2][j + 1], ans);
			/*
			01
			11
			01
			*/
			ans = max(sum - board[i][j] - board[i + 2][j], ans);
			/*
			10
			11
			10
			*/
			ans = max(sum - board[i][j + 1] - board[i + 2][j + 1], ans);
		}
	}
	// 3 x 2
	for (int i = 0; i <= n - 2; ++i) {
		for (int j = 0; j <= m - 3; ++j) {
			int sum = 0;
			for (int k = i; k < i + 2; ++k) {
				for (int l = j; l < j + 3; ++l) {
					sum += board[k][l];
				}
			}
			/*
			111
			001
			*/
			ans = max(sum - board[i + 1][j] - board[i + 1][j + 1], ans);
			/*
			001
			111
			*/
			ans = max(sum - board[i][j] - board[i][j + 1], ans);
			/*
			011
			011
			*/
			ans = max(sum - board[i][j] - board[i + 1][j], ans);
			/*
			110
			110
			*/
			ans = max(sum - board[i][j + 2] - board[i + 1][j + 2], ans);
			/*
			100
			111
			*/
			ans = max(sum - board[i][j + 1] - board[i][j + 2], ans);
			/*
			111
			100
			*/
			ans = max(sum - board[i + 1][j + 1] - board[i + 1][j + 2], ans);
			/*
			011
			110
			*/
			ans = max(sum - board[i][j] - board[i + 1][j + 2], ans);
			/*
			110
			011
			*/
			ans = max(sum - board[i][j + 2] - board[i + 1][j], ans);
			/*
			010
			111
			*/
			ans = max(sum - board[i][j] - board[i][j + 2], ans);
			/*
			111
			010
			*/
			ans = max(sum - board[i + 1][j] - board[i + 1][j + 2], ans);
		}
	}
	return ans;
}
