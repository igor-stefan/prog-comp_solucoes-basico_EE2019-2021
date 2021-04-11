#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e4 + 5;

int main(){
    int n, k, fun[Nmax], time[Nmax], ans = INT_MIN;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &fun[i], &time[i]);
    for(int i = 1; i <= n; i++){
        if(time[i] > k)
            fun[i] -= time[i] - k;
        ans = max(ans, fun[i]);
    }
    printf("%d\n", ans);

    return 0;
}