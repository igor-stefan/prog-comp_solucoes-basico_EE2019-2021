#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3 + 5;
bool cant_be_root[Nmax];

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d %d", &a, &b), cant_be_root[a] = true, cant_be_root[b] = true;
    printf("%d\n", n - 1);
    for(int i = 1; i <= n; i++)
        if(!cant_be_root[i]){
            for(int j = 1; j <= n; j++)
                if(i != j)
                    printf("%d %d\n", i, j);
            break;
        }
    return 0;
}