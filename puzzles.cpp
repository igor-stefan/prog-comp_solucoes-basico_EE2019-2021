#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e1 + 50;

int main(){
    int n , m, a[Nmax];
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + m + 1);
    int minDiff = INT_MAX;
    for(int i = m; i >= n; i--)
        minDiff = min(minDiff, a[i] - a[i - n + 1]);
    printf("%d\n", minDiff);

    return 0;
}