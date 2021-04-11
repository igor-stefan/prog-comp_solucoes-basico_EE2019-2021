#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e5 + 1;
const int Tmax = 2750131 + 1;

bool numbers[Tmax];
int prime[Nmax];

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
            prime[++cont] = i;
            for(int j = i * 2; j <= Tmax - 1; j += i)
                    numbers[j] = true;
        }
        if(cont == n)
            break;
    }    
}   

vector<int> b, c;

int main(){
    int a[100], temp;
    sieve(Nmax - 2);
    for(int i = 1; i <= 20; i++)
        scanf("%d", &temp), a[i] = temp, b.push_back(temp);
    c = b;
    for(auto x : b)
        cout << x << " ";
    cout << "\n";
    for(int i = 1; i <= 20; i++)
        if(isPrime(a[i]))
            b.push_back(prime[a[i]]);
        else
            b.push_back(a[i] / leastPrimeDivideN(a[i]));
    for(auto x : b)
        cout << x << " ";
    cout << "\n";
    random_shuffle(b.begin(), b.end());
    for(auto x : b)
        cout << x << " ";
    cout << "\n";
}