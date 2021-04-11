#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 5;

int roudness(long long n){
    int cont = 0;
    while(n % 10 == 0){
        n /= 10;
        cont++;
    }
    return cont;
}

int maximalRoudness(unsigned long long a[], int n, int k){
    return 0;
}

int main() {
    unsigned long long a[Nmax];
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%llu", &a[i]);
    printf("%d\n", maximalRoudness(a, n, k));
    return 0;
}