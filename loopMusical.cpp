#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e4 + 4;

int main(){
    int n, a[Nmax], cont = 0;
    while(1){
        scanf("%d", &n);
        if(n == 0)
            break;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        a[0] = a[n];
        a[n + 1] = a[1];
        for(int i = 1; i <= n; i++){
            if(a[i + 1] > a[i] and a[i - 1] > a[i])
                cont++;
            if(a[i + 1] < a[i] and a[i - 1] < a[i])
                cont++;
        }
        printf("%d\n", cont);
        cont = 0;
    }
    return 0;
}