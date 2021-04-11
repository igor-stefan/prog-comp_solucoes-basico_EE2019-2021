#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 4;

int main(){
    int n, k, a[Nmax];
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    long long sum = 0;
    int i, minSeq = INT_MAX;
    for(i = 1; i <= n; i++){
        if(a[i] < 0 and k){
            sum += -a[i];
            k--;
            minSeq = min(minSeq, -a[i]);
        }
        else{
            minSeq = min(minSeq, a[i]);
            break;
        }
    }
    if(k % 2)
        sum += -2 * minSeq;
    for(int j = i; j <= n; j++)
        sum += a[j];
    printf("%lld\n", sum);
    return 0;
}