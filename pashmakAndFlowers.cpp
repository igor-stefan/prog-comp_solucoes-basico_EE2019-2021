#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e5 + 3;

long long ncr(int n, int r){
    long long ans = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
    if (r != 0) { 
        while (r) { 
            ans *= n, k *= r; 
            long long m = __gcd(ans, k); 
            ans /= m; 
            k /= m; 
            n--, r--;
        }  
    } 
    else
        ans = 1;  
    return ans;
} 


int main(){
    int n, temp;
    map<int, int> freq;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &temp);
        freq[temp]++;
    }
    auto it_1 = freq.begin();
    auto it_2 = freq.rbegin();
    if(freq.size() == 1)
        printf("0 %lld\n", ncr(n, 2));
    else{
        printf("%lld ", 1LL * (int)it_2 -> first - (int)it_1 -> first);
        printf("%lld\n", 1LL * (int)it_2 -> second * (int)it_1 -> second);
    }
    return 0;
}