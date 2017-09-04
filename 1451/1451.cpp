#include <iostream>
#include <cstdio>
#include <initializer_list>
#include <algorithm>
typedef long long ll;
using namespace std;

int arr[101][101];

ll func1(int n, int m) { // 가로 세 줄
	ll ans = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ll a = 0, b = 0, c = 0;
			for (int l = 0; l < i; ++l) {
				for (int k = 0; k < m; ++k) {

					a += arr[l][k];
				}
			}
			for (int l = i; l < j; ++l) {
				for (int k = 0; k < m; ++k) {
					b += arr[l][k];
				}
			}
			for (int l = j; l < n; ++l) {
				for (int k = 0; k < m; ++k) {
					c += arr[l][k];
				}
			}
			ans = max(ans, a *  b * c);
//			cout << "func1\n"<<"a : " << a << endl << "b : " << b << endl << "c : " << c << endl << "a * b * c : "<< a*b*c << endl;
		}
	}
	return ans;
}

ll func2(int n, int m) {	//	세로 세 줄
	ll ans = 0;
	for (int i = 1; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			ll a = 0, b = 0, c = 0;
			for (int l = 0; l < i; ++l) {
				for (int k = 0; k < n; ++k) {
					a += arr[k][l];
				}
			}
			for (int l = i; l < j; ++l) {
				for (int k = 0; k < n; ++k) {
					b += arr[k][l];
				}
			}
			for (int l = j; l < m; ++l) {
				for (int k = 0; k < n; ++k) {
					c += arr[k][l];
				}
			}
//			cout << "func2\n"<<"a : " << a << endl << "b : " << b << endl << "c : " << c << endl << "a * b * c : "<< a*b*c << endl;
			ans = max(ans, a * b * c);
		}
	}
	return ans;
}

ll func3(int n, int m) { 
	ll ans = 0;
	for (int i = 1; i < n; ++i) {
		ll a = 0, b = 0, c = 0;
		for (int j = i; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				a += arr[j][k];
			}
		}
		for (int j = 1; j < m; ++j) {
			for (int k = 0; k < i; ++k) {
				for (int l = 0; l < j; ++l) {
					b += arr[k][l];
				}
				for (int l = j; l < m; ++l) {
					c += arr[k][l];
				}
			}
//			cout << "func3\n"<<"a : " << a << endl << "b : " << b << endl << "c : " << c << endl << "a * b * c : "<< a*b*c << endl;
			ans = max(ans, a * b * c);
			b = c = 0;
		}
	}
	return ans;
}

ll func4(int n, int m) {
	ll ans = 0;
	for (int i = 1; i < n; ++i) {
		ll a = 0, b = 0, c = 0;
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < m; ++k) {
				a += arr[j][k];
			}
		}
		for (int j = 1; j < m; ++j) {
			for (int k = i; k < n; ++k) {
				for (int l = 0; l < j; ++l) {
					b += arr[k][l];
				}
				for (int l = j; l < m; ++l) {
					c += arr[k][l];
				}
			}
//			cout << "func4\n"<<"a : " << a << endl << "b : " << b << endl << "c : " << c << endl << "a * b * c : "<< a*b*c << endl;
			ans = max(ans, a * b * c);
			b = c = 0;
		}
	}
	return ans;
}

ll func5(int n, int m) {
	ll ans = 0;
	for (int i = 1; i < m; ++i) {
		ll a = 0, b = 0, c = 0;
		for (int j = i; j < m; ++j) {
			for (int k = 0; k < n; ++k) {
				a += arr[k][j];
			}
		}
		for (int j = 1; j < n; ++j) {
			for (int k = 0; k < j; ++k) {
				for (int l = 0; l < i; ++l) {
					b += arr[k][l];
				}
			}
			for (int k = j; k < n; ++k) {
				for (int l = 0; l < i; ++l) {
					c += arr[k][l];
				}
			}
//			cout << "func5\n"<<"a : " << a << endl << "b : " << b << endl << "c : " << c << endl << "a * b * c : "<< a*b*c << endl;
			ans = max(ans, a * b * c);
			b = c = 0;
		}
	} 
	return ans;
}

ll func6(int n, int m) {
	ll ans = 0;
	for (int i = 1; i < m; ++i) {
		ll a = 0, b = 0, c = 0;
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < n; ++k) {
				a += arr[k][j];
			}
		}
		for (int j = 1; j < n; ++j) {
			for (int k = i; k < m; ++k) {
				for (int l = 0; l < j; ++l) {
					b += arr[l][k];
				}
			}
			for (int k = i; k < m; ++k) {
				for (int l = j; l < n; ++l) {
					c += arr[l][k];
				}
			}
//			cout << "func6\n"<<"a : " << a << endl << "b : " << b << endl << "c : " << c << endl << "a * b * c : "<< a*b*c << endl;
			ans = max(ans, a * b * c);
			b = c = 0;
		}
	}
	return ans;
}

int main() {
	int n, m;

	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &arr[i][j]);
		}
	}
	cout << max(max(max(max(max(func1(n, m), func2(n, m)), func3(n, m)), func4(n, m)), func5(n, m)), func6(n, m));	
	//ll q = max({func1(n, m), func2(n, m), func3(n, m), func4(n, m)});
}

