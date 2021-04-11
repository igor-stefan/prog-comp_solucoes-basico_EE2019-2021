#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(){
    int t;
    scanf("%d", &t);
    getchar();
    for(int i = 1; i <= t; i++){
        string a, s = "";
        getline(cin, a);        
        int n = a.length();
        int k = n / 2;
            if(n % 2){
                s += a[k];
                for(int i = 1; i <= k; i++){
                    if(a[k - i] > a[k + i]){
                        s += a[k - i];
                        s += a[k + i];
                    }
                    else{
                        s += a[k + i];
                        s += a[k - i];
                    }
                }
            }else{
                if(a[k] > a[k - 1]){
                    s += a[k];
                    s += a[k - 1]; 
                } else {
                    s += a[k - 1];
                    s += a[k];
                }
                for(int i = 1; i <= k - 1; i++){
                    if(a[k - i - 1] > a[k + i]){
                        s += a[k - i - 1];
                        s += a[k + i];
                    }
                    else{
                        s += a[k + i];
                        s += a[k - i - 1];
                    }
                }
            }
        long long ans = 0;
        for(int j = 0; j < (int)s.length(); j++){
            if(s[j] == '1'){
                ans *= 2;
                ans++;
                ans %= mod;
            }
            else{
                ans *= 2;
                ans %= mod;
            }
        }
    printf("Case #%d: %lld\n", i, ans);
    }
    return 0;
}