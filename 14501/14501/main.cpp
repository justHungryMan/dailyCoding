#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
int n;
int person[20][2];
int dp[20];
int solve(int d){
    if(d > n)    //n일 넘으면 종료
        return 0;
    
    int &ret = dp[d];      //n일 까지 해결 가능한 일의 최대값
    if(ret != -1) return ret;
    
    ret = 0;
    for(int i=d;i<=n;i++){
        if(i + person[i][0] > n+1)
            continue;
        ret = max(ret, solve(i+person[i][0])+person[i][1] );
    }
    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> person[i][0] >> person[i][1];
    }
    
    cout << solve(1);
}
