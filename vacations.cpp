#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 5;
int pred[Nmax], dp[Nmax][3] = {INT_MAX};



int vacation(int a[], int n){
    if(a[1] == 1 || a[1] == 3) //if I go to contest then I will not rest
        dp[1][1] = 0;
    if(a[1] == 2 || a[1] == 3) //if I go to gym then I will not rest
        dp[1][2] = 0;
    dp[1][0] = 1; //if I rest the number of days rested is 1;

    for(int day = 2; day <= n; day++){
        dp[day][0] = 1 + min(dp[day - 1][0], min(dp[day - 1][1], dp[day - 1][2]));
        if(a[day] == 1 || a[day] == 3)
            dp[day][1] = min(dp[day - 1][0], dp[day - 1][2]);
        if((a[day] == 2 || a[day] == 3))
            dp[day][2] = min(dp[day-1][0], dp[day - 1][1]);
    }
    return min(dp[n][0], min(dp[n][1],dp[n][2]));
}

int main () {
    for(int i = 0; i < Nmax; i++)
        for(int j = 0; j < 3; j++)
            dp[i][j] = INT_MAX;
    int n, a[Nmax];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << vacation(a, n) << endl;
    return 0;
}