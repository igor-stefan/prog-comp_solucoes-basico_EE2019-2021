#include<bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e5 + 2;


int main(){
    int n, gas[Nmax];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &gas[i]);
    sort(gas + 1, gas + n + 1);
    double ans = INT_MAX;
    for(int i = 1; i <= n; i++){
        if(gas[i] > i){
            printf("-1\n");
            return 0;
        }
        else
            ans = min(ans, (double) gas[i] / i);
    }
    printf("%.7f\n", ans);
    return 0;
}