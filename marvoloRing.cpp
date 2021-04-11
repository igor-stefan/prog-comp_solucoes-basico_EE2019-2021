#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;
long long dpP[Nmax], dpQ[Nmax], dpR[Nmax];

// long long numOfPotions(int a[], int n, int p, int q, int r){
//     long long ans = INT_MIN;
//     for(int i = 1; i <= n; i++)
//         for(int j = 1; j <= n; j++)
//             for(int k = 1; k <= n; k++)
//                 if(ans < p * a[i] + q * a[j] + r * a[k] * 1LL)
//                     ans = p * a[i] + q * a[j] + r * a[k] * 1LL;
//     return ans;
// }

long long numOfPotions2 (int a[], int n, int p, int q, int r){

    dpP[1] = 1LL * a[1] * p;
    for(int i = 2; i <= n; i++)
        dpP[i] = max(dpP[i - 1], 1LL * a[i] * p);
    
    dpQ[1] = dpP[1] + 1LL * a[1] * q;
    for(int i = 2; i <= n; i++)
        dpQ[i] = max(dpQ[i - 1], dpP[i] + 1LL * a[i] * q );
    
    dpR[1] = dpQ[1] + 1LL * a[1] * r;
    for(int i = 2; i <= n; i++)
        dpR[i] = max(dpR[i - 1], dpQ[i] + 1LL * a[i] * r);
    return dpR[n];
}


int main() {
    int n, p, q, r, a[Nmax];
    scanf("%d %d %d %d", &n, &p, &q, &r);
    for(int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);
    printf("%lld\n", numOfPotions2(a, n, p, q, r));

    return 0;
}