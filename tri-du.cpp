#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 * 5 + 3;

int main(){
    int j, r;
    while(scanf("%d %d", &j, &r) == 2){
        printf("%d\n", max(j, r));
    }
    return 0;
}