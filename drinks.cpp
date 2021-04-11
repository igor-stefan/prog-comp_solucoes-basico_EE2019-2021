#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, fraction;
    scanf("%d", &n);
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &fraction);
        sum += fraction;
    }
    printf("%.12f\n", (double) sum / n);
    return 0;
}