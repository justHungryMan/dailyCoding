#include <cstdio>
#include <queue>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdbool>
using namespace std;
int n, m;


int solve (char map[10][10], int count) {
	char newMap[4][10][10];
	int ans = 11;
	bool blueCheck[4] = {false, false, false, false};
	
	if (count > 10) return 11;

	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				newMap[k][i][j] = map[i][j];
			}
		}
	}

	// east
	for (int i = 0; i < n; ++i) {
		bool red = false;
		bool blue = false;
		for (int j = m - 1; j >= 0; --j) {
			if (newMap[0][i][j] == 'R') {
				for (int k = j + 1; k < m; ++k) {
					if (newMap[0][i][k] == '.') {
						newMap[0][i][k] = 'R';
						newMap[0][i][k - 1] = '.';
					}
					else if (newMap[0][i][k] == 'O') {
						newMap[0][i][k - 1] = '.';	
						red = true;
						break;
					}
					else break;
				}
			}
			else if (newMap[0][i][j] == 'B') {
				for (int k = j + 1; k < m; ++k) {
					if (newMap[0][i][k] == '.') {
						newMap[0][i][k] = 'B';
						newMap[0][i][k - 1] = '.';
					}
					else if (newMap[0][i][k] == 'O') {
						newMap[0][i][k - 1] = '.';
						blue = true;
						break;
					}
					else break;
				}
			}
		}
		if (red && !blue) {
			//printf("%d over\n", count);
			ans = min(ans, count);
		}
		else if (blue) {
			blueCheck[0] = true;
			break;
		}
	}
	
	// west
	for (int i = 0; i < n; ++i) {
		bool red = false;
		bool blue = false;
		for (int j = 0; j < m; ++j) {
			if (newMap[1][i][j] == 'B') {
				for (int k = j - 1; k >= 0; --k) {
					if (newMap[1][i][k] == '.') {
						newMap[1][i][k] = 'B';
						newMap[1][i][k + 1] = '.';
					}
					else if (newMap[1][i][k] == 'O') {
						newMap[1][i][k + 1] = '.';
						blue = true;
						break;
					}
					else break;
				}
			}
			else if (newMap[1][i][j] == 'R') {
				for (int k = j - 1; k >= 0 ; --k) {
					if (newMap[1][i][k] == '.') {
						newMap[1][i][k] = 'R';
						newMap[1][i][k + 1] = '.';
					}
					else if (newMap[1][i][k] == 'O') {
						newMap[1][i][k + 1] = '.';
						red = true;
						break;
					}
					else break;
				}
			}
		}
		if (red && !blue) {
			//printf("%d over\n", count);
			ans = min(ans, count);
		}
		else if (blue) {
			blueCheck[1] = true;
			break;
		}
	}

	// north
	for (int j = 0; j < m; ++j) {
		bool red = false;
		bool blue = false;
		for (int i = 0; i < n; ++i) {
			if (newMap[2][i][j] == 'B') {
				for (int k = i - 1; k >= 0; --k) {
					if (newMap[2][k][j] == '.') {
						newMap[2][k][j] = 'B';
						newMap[2][k + 1][j] = '.';
					}
					else if (newMap[2][k][j] == 'O') {
						newMap[2][k + 1][j] = '.';
						blue = true;
						break;
					}
					else break;
				}
			}
			else if (newMap[2][i][j] == 'R') {
				for (int k = i - 1; k >= 0 ; --k) {
					if (newMap[2][k][j] == '.') {
						newMap[2][k][j] = 'R';
						newMap[2][k + 1][j] = '.';
					}
					else if (newMap[2][k][j] == 'O') {
						newMap[2][k + 1][j] = '.';
						red = true;
						break;
					}
					else break;
				}
			}
		}
		if (red && !blue) {
			//printf("%d over\n", count);
			ans = min(ans, count);
		}
		else if (blue) {
			blueCheck[2] = true;
			break;
		}
	}

	// south
	for (int j = 0; j < m; ++j) {
		bool red = false;
		bool blue = false;
		for (int i = n - 1; i >= 0; --i) {
			if (newMap[3][i][j] == 'R') {
				for (int k = i + 1; k < n; ++k) {
					if (newMap[3][k][j] == '.') {
						newMap[3][k][j] = 'R';
						newMap[3][k - 1][j] = '.';
					}
					else if (newMap[3][k][j] == 'O') {
						newMap[3][k - 1][j] = '.';
						red = true;
						break;
					}
					else break;
				}
			}
			else if (newMap[3][i][j] == 'B') {
				for (int k = i + 1; k < n; ++k) {
					if (newMap[3][k][j] == '.') {
						newMap[3][k][j] = 'B';
						newMap[3][k - 1][j] = '.';
					}
					else if (newMap[3][k][j] == 'O') {
						newMap[3][k - 1][j] = '.';
						blue = true;
						break;
					}
					else break;
				}
			}
		}
		if (red && !blue) {
			//printf("%d over\n", count);
			ans = min(ans, count);
		}
		else if (blue) {
			blueCheck[3] = true;
			break;
		}
	}

	/*
	printf("nowMap count : %d\n", count);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%c", map[i][j]);
		}
		puts("");
	}
	printf("\nEast west north south\n");

	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				printf("%c", newMap[k][i][j]);
			}
			puts("");
		}
		puts("");
	}
*/	
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (newMap[k][i][j] != map[i][j] && !blueCheck[k]) {
					j = m;
					i = n;
					ans = min(ans, solve(newMap[k], count + 1));
				}
			}
		}
	}
	/*
	for (int k = 0; k < 4; ++k) {
		ans = min(ans, solve(newMap[k], count + 1));
	}
*/

	return ans;
}

int main() {
	char map[10][10];
	int ans;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf(" %c", &map[i][j]);
		}
	}
	ans = solve(map, 1);
	if (ans == 11) ans = -1;
	cout << ans << endl;
}
