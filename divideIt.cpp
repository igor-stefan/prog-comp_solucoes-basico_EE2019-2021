#include <bits/stdc++.h>

using namespace std;

int query(long long n, int moves){
    if(n == 1)
        return moves;
    if(n % 2 == 0)
        return query(n / 2, moves + 1);
    else if(n % 3 == 0)
        return query(2 * n / 3, moves + 1);
    else if(n % 5 == 0)
        return query(4 * n / 5, moves + 1);
    else 
        return -1;
}


int main(){
    int q;
    long long n;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        scanf("%lld", &n);
        printf("%d\n", query(n, 0));
    }
    return 0;
}