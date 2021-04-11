#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3 + 3;
int dp[Nmax];

struct client{
    int length, val;
};

int pipeCuttig(int n, int t, client a[]){
    for(int i = 0; i <= t; i++)
        for(int j = 1; j <= n; j++)
            if(a[j].length <= i)
                dp[i] = max(dp[i], dp[i - a[j].length] + a[j].val);
    return dp[t];
}

int main(){
    int n, t;
    client a[Nmax];
    scanf("%d %d", &n, &t);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &a[i].length, &a[i].val);
    printf("%d\n", pipeCuttig(n, t, a));
    return 0;
}