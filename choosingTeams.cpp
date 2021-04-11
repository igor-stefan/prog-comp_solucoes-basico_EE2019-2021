#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e3 + 2; 

int main(){
    int n, k, a[Nmax];
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        a[i] = 5 - a[i];
    int cont = 0;
    for(int i = 3; i <= n; i += 3)
        if(a[i] >= k)
            cont++;
    printf("%d\n", cont);
    return 0;
}