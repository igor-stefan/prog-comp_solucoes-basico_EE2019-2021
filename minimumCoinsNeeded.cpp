#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3 + 3;

int minimumCoins(int a[], int n, int sum){
    vector<int> dp(sum + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= sum; i++)
        for(int j = 0;  j < n; j++)
            if(a[j] <= i)
                dp[i] = min (dp[i - a[j]] + 1, dp[i]);
    if(dp[sum] == INT_MAX || dp[sum] == INT_MIN)
        return -1;
    return dp[sum];
}

int main() {
    int n, sum, a[] = {1, 5, 10, 20, 100};
    scanf("%d",&sum);
    printf("%d\n",minimumCoins(a, 5, sum));
    return 0;
}
