#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int n;
vector < string > v;

long long answer() {
		long long MIN = LLONG_MAX, MAX = LLONG_MIN;
			do {
						string now;
								for (int i = 0; i < v.size(); ++i) {
												now += v[i];
														}
										MIN = min(MIN, stoll(now));
												MAX = max(MAX, stoll(now));
													} while(next_permutation(v.begin(), v.end()));
				return MIN + MAX;
}
	
int main() {
		
		cin >> n;
			for (int i = 0; i < n; ++i) {
						string input;
								cin >> input;
										v.push_back(input);
											}
				sort(v.begin(), v.end());
					cout << answer();
					  return 0;
}

