#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 3;

void solve(int n, int k){
    for(int i = n; i >= n - k + 1; i--)
        printf("%d ", i);
    for(int i = 1; i <= n - k; i++)
        printf("%d ", i);
    printf("\n");
}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    solve(n, k);
    return 0;
}