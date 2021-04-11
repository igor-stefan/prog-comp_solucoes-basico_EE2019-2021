#include <bits/stdc++.h>

using namespace std;

int chips(int n, int m){
    int i;
    for(i = 1; i <= n; i++){
        if(m < i)
            return m;
        m -= i;
    }
    return chips(n, m);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n",chips(n, m));
    return 0;
}