#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 3;

int main(){
    int n, t, a[Nmax];
    scanf("%d %d", &n, &t);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int cont = 0, i = 1, j = 1, sum = 0, maxCont = INT_MIN;
    for(i = 1; i <= n; i++){
        while(sum <= t and j <= n)
            sum += a[j++], cont++;
        if(sum > t)
            sum -= a[i], cont--;
        maxCont = max(cont, maxCont);
        if(j > n)
            break;
    }
    if(maxCont == INT_MIN)
        maxCont = cont;
    printf("%d\n", maxCont);
}