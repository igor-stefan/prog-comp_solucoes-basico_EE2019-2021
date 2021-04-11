#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 3;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        int n, a[Nmax], cont = 0, cont1 = 0, cont2 = 0, ans = 0;
        scanf("%d", &n);
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[j]);
            a[j] %= 3;
        }
        for(int j = 1; j <= n; j++)
            if(a[j] == 0)
                cont++;
            else if(a[j] == 2)
                cont2++;
            else
                cont1++;
        int temp = min(cont1, cont2);
        ans = cont + temp + (cont1 - temp) / 3 + (cont2 - temp) / 3;
        printf("%d\n", ans);
    }


    return 0;
}