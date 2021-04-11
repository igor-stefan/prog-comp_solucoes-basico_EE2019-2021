#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 3;

long long query(int a, int b, int x, int y, int n){
    long long ans = 1e18;
    for(int i = 1; i <= 2; i++){
        int k = min(a - x, n);
        int k1 = min(n - k, b - y);
        ans = min(ans, 1LL * (a - k) * (b - k1));
        swap(a, b), swap(x, y);
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        int a, b, x, y, n;
        scanf("%d %d %d %d %d", &a, &b, &x, &y, &n);
        printf("%lld\n", query(a, b, x, y, n));
    }
    return 0;
}