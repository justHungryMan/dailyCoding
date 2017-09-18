#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


int main() {
    int n;
    string answer = "Possible\n";
    vector <string> v[101];
    bool check[10001];
    scanf("%d\n", &n);

    for (int i = 0; i <= n; ++i) {
        char str[5000000];
        fgets(str, 5000000, stdin);
        string line(str);
        string buf;
        stringstream ss(str);
        while (ss >> buf)
            v[i].push_back(buf);
    }
    for (int i = 0; i < v[n].size(); ++i) {
        check[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        int index = 0;
        for (int j = 0; j < v[n].size(); ++j) {
            if (v[n][j] == v[i][index]) {
                index++;
                check[j] = true;
            }
            if (v[i].size() == index) break;
        }
    }
    for (int i = 0; i < v[n].size(); ++i) {
        if (check[i] == false) answer = "Impossible\n";
    }

    cout << answer;

}
