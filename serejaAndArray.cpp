#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 4;

int adjust[Nmax];
int main(){
    int n, m, a[Nmax];
    scanf("%d %d", &n, &m);
    for(int i = 1; i<= n; i++)
        scanf("%d", &a[i]);
    int type, acc, b, c, sum = 0;
    for(int i = 1; i <= m; i++){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d %d", &b, &c);
            adjust[b] = c - sum - a[b];
        }
        else if(type == 2){
            scanf("%d", &b);
            sum += b;
        }
        else{
            scanf("%d", &b);
            printf("%d\n", a[b] + sum + adjust[b]);
        }
    }
    return 0;
}