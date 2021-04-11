#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e5 + 1;
const int Tmax = 2750131 + 1;

bool numbers[Tmax];
int prime[Nmax];
multiset<int> myset;

bool isPrime(int n){
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

int leastPrimeDivideN(int n){
    int i;
    for(i = 1; i <= Nmax - 2; i++)
        if(n % prime[i] == 0)
            break;
    return prime[i];
}

void sieve(int n){
    int cont = 0;
    for(int i = 2; i <= Tmax - 1; i++){
        if(!numbers[i]){
            prime[i] = ++cont;
            for(int j = i * 2; j <= Tmax - 1; j += i)
                    numbers[j] = true;
        }
        if(cont == n)
            break;
    }    
}   

int main(){
    int n, temp;
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i++)
        scanf("%d", &temp), myset.insert(temp);
    sieve(Nmax - 2);
    for(auto it = myset.rbegin(); it != myset.rend(); it++){
        // cout << "it = " << *it << "\n";
        if(isPrime(*it)){
            auto x = myset.find(prime[*it]);
            // cout << "x = " << *x << "\n";
            if(x != myset.end())
                myset.erase(*it);
        }
        else{
            auto x = myset.find(*it / leastPrimeDivideN(*it));
            // cout << "x = " << *x << "\n";
            if(x != myset.end())
                myset.erase(*it);
        }
    }
    for(auto x : myset)
        printf("%d ", x);
    printf("\n");
}