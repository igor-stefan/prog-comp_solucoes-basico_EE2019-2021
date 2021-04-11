#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;

void verifyCities(int a[], int n){
    int freq = 0, minDist = INT_MAX, index = -1;
    for(int i = 1; i <= n; ++i){
        if(a[i] < minDist){
            minDist = a[i];
            freq = 0;
            index = i;
        }
        if(a[i] == minDist)
            ++freq;
    }
    if(freq != 1)
        printf("Still Rozdil\n");
    else
        printf("%d\n", index);
}

int main(){ 
    int n, a[Nmax];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    verifyCities(a, n);
    return 0;
}