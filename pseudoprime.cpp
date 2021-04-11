#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e18;
long long fastExpo(int a, int n, int MOD){
    if(n == 0) return 1;
    if(n % 2 == 0) return fastExpo((1LL * a * a) % MOD, n / 2, MOD);
    return 1LL * a * fastExpo(a,n - 1,MOD) % MOD;
}


bool isPseudoPrime(int a, int p){    
    if (fastExpo(a, p, p) == a) 
        return true; 
    return false; 
} 

bool byDefinition_isPrimeNumber(int n){
    if(n==0 or n==1) 
        return false;
    for(int i = 2; i * i < n; i++)
        if(n % i == 0) 
            return false;
    return true;
}

int main(){
    int a, p;
    while(scanf("%d %d", &p, &a) == 2 and a and p){
        if(byDefinition_isPrimeNumber(p))
            printf("no\n");
        else{
            if(isPseudoPrime(a, p))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
