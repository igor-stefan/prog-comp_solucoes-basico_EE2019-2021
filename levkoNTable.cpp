#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 4;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) 
                printf("%d ", k);
            else
                printf("0 ");
            
        }
    printf("\n");
    }
    return 0;
}