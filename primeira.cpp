#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        int a1 = m - n;
        int an = m - 1;
        long long ans = (1LL * (a1 + an) * n) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}