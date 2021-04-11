#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1.5 * 1e5 + 4;

int minimumSum(int a[], int n, int k){
    long long sum = 0, minS;
    int index;
    for(int i = 1; i <= k; i++)
        sum += a[i];
    minS = sum;
    index = 1;
    for(int i = k + 1; i <= n; i++){
        sum += a[i] - a[i - k];
        if(sum < minS){
            minS = sum;
            index = i - k + 1;
        }
    }
    return index;
}

int main(){
    int n, k, a[Nmax];
    scanf("%d %d", &n, &k);
    for(int i = 1; i<= n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", minimumSum(a, n, k));
    return 0;
}