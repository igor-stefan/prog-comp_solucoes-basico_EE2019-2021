#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e5 + 1;
const int Tmax = 2750131 + 1;

bool numbers[Tmax], visited[2 * Nmax];
int prime[Nmax];
vector<int> ans;

int leastPrimeDivideN(int n){
    int i;
    for(i = 1; i <= Nmax - 2; i++)
        if(n % prime[i] == 0)
            break;
    return prime[i];
}

bool find(int val, int b[], int n){
    for(int j = 1; j <= 2 * n; j++)
        if(!visited[j] and b[j] == val){
            visited[j] = true;
            return true;
        }
    return false;     
}

bool isPrime(int n){
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
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

int main(){
    vector<int> primesInB, NotPrimesInB;
    int n, b[2 * Nmax];
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i++){
        scanf("%d", &b[i])
        if(isPrime(b[i]))
            primesInB.push_back(b[i]);
        else
            NotPrimesInB.push_back(b[i]);
    }
    sort(primesInB.begin(), primesInB,end());
    sort(NotPrimesInB.begin(), NotPrimesInB.end());
    sieve(Nmax - 2);
    cout << "not primes = ";
    for(int i = 1; i <= 2 * n; i++){
        if(visited[i] or b[i] > Nmax - 1)
            continue;
        if(!isPrime(b[i])){
            cout << b[i] << " ";
            visited[i] = true;
            if(b[i] & 1){
                if(!find(b[i] / leastPrimeDivideN(b[i]), b, n))
                    visited[i] = false;
                else
                    ans.push_back(b[i]);
            }else
                if(!find(b[i] * 2, b, n))
                    visited[i] = false;
                else
                    ans.push_back(b[i]);
        }
    }
    cout << "\nprimes = ";
    for(int i = 1; i <= 2 * n; i++){
        if(visited[i] or b[i] > Nmax - 1)
            continue;
        visited[i] = true;
        cout << b[i] << " ";
        if(!find(prime[b[i]], b, n))
            visited[i] = false;
        else
            ans.push_back(b[i]);
    }
    cout << "\n";
    for(int i = 1; i <= 2 * n; i++){
        if(!visited[i])
            cout << b[i] << " ";
        else
            printf("%d ", visited[i]);
    }
    printf("\n");
    for(auto x : ans)
        printf("%d ", x);
    printf("\n");
    return 0;
}