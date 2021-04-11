#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;

int lenOfFibonacciSegment(const int a[], int i, int n){
    int ans = 0;
    while(i <= n){
    int cont = 0;
    while(i <= n and a[i] != a[i - 1] + a[i - 2])
        i++;
    while(i <= n and a[i] == a[i - 1] + a[i++ - 2])
        cont++;
    ans = max(ans, cont);
    }
return ans + 2;
}


int main () {
    int n, a[Nmax];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    if(n >= 3)
        printf("%d\n", lenOfFibonacciSegment(a, 3, n));
    else 
        printf("%d\n", n);
    return 0;
}