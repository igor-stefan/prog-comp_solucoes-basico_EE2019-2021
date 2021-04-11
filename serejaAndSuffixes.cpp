#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;
bool seen[Nmax];
int main(){
    int n, m, a[Nmax], ans[Nmax];
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ans[n] = 1;
    seen[a[n]] = true;
    for(int i = n - 1; i >= 1; i--){
        ans[i] = ans[i + 1];
        if(!seen[a[i]])
            ans[i]++;
        seen[a[i]] = true;
    }
    int amanda;
    for(int i = 1; i <= m; i++){
        scanf("%d", &amanda);
        printf("%d\n", ans[amanda]);
    }
    return 0;
}