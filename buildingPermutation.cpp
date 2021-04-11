#include <bits/stdc++.h>

using namespace std;

const int Nmax = 3 * 1e5 + 3;

int main(){
    int n, a[Nmax];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", & a[i]);
    sort(a + 1, a + n + 1);
    long long minMoves = 0;
    for(int i = 1; i <= n; i++)
        minMoves += abs(a[i] - i);
    printf("%lld\n", minMoves);
    return 0;
}