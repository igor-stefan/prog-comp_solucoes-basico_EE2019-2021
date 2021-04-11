#include <bits/stdc++.h>

using namespace std;

const int Nmax = 4 * 1e3 + 4;

int dp[Nmax];

int cutRibbon(int n, int a, int b, int c){
    for(int i = 1; i <= n; i++)
        dp[i] = INT_MIN;
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        if(a <= i)
            dp[i] = max(dp[i], dp[i - a] + 1);
        if(b <= i)
            dp[i] = max(dp[i], dp[i - b] + 1);
        if(c <= i)
            dp[i] = max(dp[i], dp[i - c] + 1);
    }
    return dp[n];
}

int main(){
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    printf("%d\n", cutRibbon(n, a, b, c));
    return 0;
}