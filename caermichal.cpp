#include <bits/stdc++.h>

using namespace std;

int fastExpo(int a, int n, int MOD){
    if(n==0) return 1;
    if(n%2 == 0) return fastExpo((1LL*a*a)%MOD,n/2,MOD);
    return 1LL * a * fastExpo(a,n-1,MOD) % MOD;
}


bool isCarmichaelNumber(int n){ 
    for (int x = 2; x < n; x++) {  
        if (__gcd(x, n) == 1) 
            if (fastExpo(x, n - 1, n) != 1) 
                return false; 
    } 
    return true; 
} 

int main(){
    int k;
    while(cin >> k){
        if(k == 0)
            break;
        if(isCarmichaelNumber(k))
            printf("The number %d is a Carmichael number.\n", k);
        else
            printf("The number %d is normal.\n", k);
    }
    return 0;
}
