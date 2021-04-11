#include <bits/stdc++.h>

using namespace std;

const int Nmax = 50 + 4;

int main(){
    int n = -1;
    int a[Nmax];
    while(true){
        scanf("%d", &n);
        if(n == 0)
            break;
        int pair = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(__gcd(a[i], a[j]) == 1)
                    pair++;
        pair /= 2;
        int total = (n * (n - 1)) / 2;
        if(pair != 0)
            printf("%.6f\n", sqrt((double) (6 * total) / pair));
        else
            printf("No estimate for this data set.\n");    
    }
    return 0;
}