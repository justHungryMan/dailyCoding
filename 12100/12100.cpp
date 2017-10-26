#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int solve(int map[21][21], int count) {
	int newMap[4][21][21];
	int ans = 0;
	if (count >= 5) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				ans = max(ans, map[i][j]);
			}
		}
		return ans;
	}
	// initialize

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0 ; k < n; ++k) {
				newMap[i][j][k] = map[j][k];
			}
		}
	}

	// east
	for (int h = 0; h < n; ++h) {
		for (int i = n - 1; i >= 0; --i) {
			if (newMap[0][h][i] != 0) {
				for (int j = i - 1; j >= 0; --j) {
					if (newMap[0][h][i] == newMap[0][h][j]) {
						newMap[0][h][i] *= 2;
						newMap[0][h][j] = 0;
						i = j;
						break;
					}
					else if (newMap[0][h][j] == 0) continue;
					else break;
				}
			}
		}
	}
	
	for (int h = 0; h < n; ++h) {
		for (int i = n - 1; i >= 0; --i) {
			if (newMap[0][h][i] == 0) {
				for (int j = i - 1; j >= 0; --j) {
					if (newMap[0][h][j] != 0) {
						newMap[0][h][i] = newMap[0][h][j];
						newMap[0][h][j] = 0;
						break;
					}
				}
			}
		}
	}
	
	// west
	for (int h = 0; h < n; ++h) {
		for (int i = 0; i < n; ++i) {
			if (newMap[1][h][i] != 0) {
				for (int j = i + 1; j < n; ++j) {
					if (newMap[1][h][i] == newMap[1][h][j]) {
						newMap[1][h][i] *= 2;
						newMap[1][h][j] = 0;
						i = j;
						break;
					}
					else if (newMap[1][h][j] == 0) continue;
					else break;
				}
			}
		}
	}

	for (int h = 0; h < n; ++h) {
		for (int i = 0; i < n; ++i) {
			if (newMap[1][h][i] == 0) {
				for (int j = i + 1; j < n; ++j) {
					if (newMap[1][h][j] != 0) {
						newMap[1][h][i] = newMap[1][h][j];
						newMap[1][h][j] = 0;
						break;
					}
				}	
			}
		}
	}

	// south
	for (int w = 0; w < n; ++w) {
		for (int i = n - 1; i >= 0; --i) {
			if (newMap[2][i][w] != 0) {
				for (int j = i - 1; j >= 0; --j) {
					if (newMap[2][i][w] == newMap[2][j][w]) {
						newMap[2][i][w] *= 2;
						newMap[2][j][w] = 0;
						i = j;
						break;
					}
					else if (newMap[2][j][w] == 0) continue;
					else break;
				}
			}
		}
	}

	for (int w = 0; w < n; ++w) {
		for (int i = n - 1; i >= 0; --i) {
			if (newMap[2][i][w] == 0) {
				for (int j = i - 1; j >= 0; --j) {
					if (newMap[2][j][w] != 0) {
						newMap[2][i][w] = newMap[2][j][w];
						newMap[2][j][w] = 0;
						break;
					}
				}
			}
		}
	}

	// north
	for (int w = 0; w < n; ++w ) {
		for (int i = 0; i < n; ++i) {
			if (newMap[3][i][w] != 0) {
				for (int j = i + 1; j < n; ++j) {
					if (newMap[3][i][w] == newMap[3][j][w]) {
						newMap[3][i][w] *= 2;
						newMap[3][j][w] = 0;
						i = j;
						break;
					}
					else if (newMap[3][j][w] == 0) continue;
					else break;
				}
			}
		}
	}
	
	for (int w = 0; w < n; ++w) {
		for (int i = 0; i < n; ++i) {
			if (newMap[3][i][w] == 0) {
				for (int j = i + 1; j < n; ++j) {
					if (newMap[3][j][w] != 0) { 
						newMap[3][i][w] = newMap[3][j][w];
						newMap[3][j][w] = 0;
						break;
					}
				}
			}
		}
	}
	ans = max(ans, solve(newMap[0], count + 1));
	ans = max(ans, solve(newMap[1], count + 1));
	ans = max(ans, solve(newMap[2], count + 1));
	ans = max(ans, solve(newMap[3], count + 1));
	return ans;
}


int main() {
	int map[21][21];

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d\n", solve(map, 0));
}
