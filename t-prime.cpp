#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 3;

bool isPerfectSquare(long long n){
    long long square_root = (long long) sqrt(n);
    if(1LL * square_root * square_root == n)
        return true;
    return false;
}

bool isPrime(long long n){
    if(n <= 1) return false;
    for(long long i = 2; 1LL * i * i <= n; i++)
        if(n % i == 0)
         return false;
    return true;
}

int main(){
    int n;
    long long a[Nmax];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
         cin >> a[i];
    for(int i = 1; i <= n; i++){
        if(isPerfectSquare(a[i]))
            if(isPrime((long long) sqrt(a[i])))
                printf("YES\n");
            else
                printf("NO\n");
        else
            printf("NO\n");
    }
    return 0;
}