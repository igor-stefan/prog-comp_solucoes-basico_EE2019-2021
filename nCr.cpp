#include <bits/stdc++.h>

using namespace std;

long long nCr(int n, int r){
    long long p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
    if (r != 0) { 
        while (r) { 
            p *= n, k *= r; 
            long long m = __gcd(p, k); 
            p /= m; 
            k /= m; 
            n--, r--;
        }  
    } 
    else
        p = 1;  
    return p;
} 

int main(){
    int a = 4, b = 1;
    printf("%lld\n", nCr(a, b));
    return 0;
}