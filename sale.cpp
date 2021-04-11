#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 5;

int main(){
    int n, m, price[Nmax], sum = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &price[i]);
    sort(price + 1, price + n + 1);
    for(int i = 1; i <= m; i++)
        if(price[i] < 0)
            sum -= price[i];
    printf("%d\n", sum);
    return 0;
}