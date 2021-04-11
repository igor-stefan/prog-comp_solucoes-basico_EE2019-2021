#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        n -= 2; m -= 2;
        int line = (n / 3);
        int col = (m / 3);
        if(n % 3)
            line++;
        if(m % 3)
            col++;
        int ans = line * col;
        printf("%d\n", ans);
    }
    return 0;
}