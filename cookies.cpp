#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 5;

int main(){
    int n, a[Nmax], sum = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int cont = 0;
    for(int i = 1; i <= n; i++)
        if((sum - a[i]) % 2)
            continue;
        else
            cont++;
    printf("%d\n", cont);
    return 0;
}