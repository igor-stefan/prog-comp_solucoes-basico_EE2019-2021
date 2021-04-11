#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 3;
int g[Nmax], dp[Nmax];

int solve(int a[], int n){
    int sum = 0, ans = INT_MIN;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            sum = 0;
            for(int k = 1; k <= n; k++){
                if(k >= i and k <= j)
                    sum +=  1 - a[k];
                else
                    sum += a[k];
            }
            ans = max(ans, sum);
        }
    }
    return ans;
}

int dpFlippingGame(int a[], int n){
    int num_of_ones = 0;
    for(int i = 1; i <= n; i++){
        if(a[i])
            g[i] = -1;
        else
            g[i] = 1;
        num_of_ones += a[i];
    }
    for(int i = 1; i <= n; i++)
        dp[i] = max(dp[i - 1] + g[i], 0);
    int maxVal = INT_MIN;
    for(int i = 1; i <= n; i++)
        maxVal = max(maxVal, dp[i]);
    if(maxVal == 0)
        return num_of_ones - 1;
    else
        return maxVal + num_of_ones;
}

int main(){
    int n, a[Nmax];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", dpFlippingGame(a, n));
    return 0;
}