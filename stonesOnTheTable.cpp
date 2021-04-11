#include <bits/stdc++.h>

using namespace std;

const int Nmax = 50 + 2;

int main (){
    int n, ans = 0;
    scanf("%d", &n);
    char a[Nmax];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 2; i <= n; i++)
        ans += a[i] == a[i - 1];
    printf("%d\n", ans);
    return 0;
}