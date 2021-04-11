#include <bits/stdc++.h>

using namespace std;

const int lim = 1e9;

int sumOfDigits(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long fastExpo(long long a, long long n){ //number, power
    long long ans = 1;
    while(n >= 1){
        if(n % 2 == 0){ //if n is even
            n /= 2;
            a = (1LL * a * a);
        }else{ //if n is odd
            n -= 1;
            ans = ((1LL * ans * a));
        }
    }
    return ans;
}

void solve(int a, int b, int c){
    int n = 81;
    vector<long long> ans;
    vector<long long> expo(n + 1);
    for(int i = 1; i <= n; i++)
        expo[i] = fastExpo(i, a) * b + c;
    for(int i = 1; i <= n; i++)
        if(expo[i] < lim and sumOfDigits(expo[i]) == i)
            ans.push_back(expo[i]);
    if(ans.empty())
        printf("0\n");
    else{
        printf("%d\n", (int) ans.size());
        for(auto k : ans)
            printf("%lld ", k);
        printf("\n");
    }

}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    solve(a, b, c);
    return 0;
}