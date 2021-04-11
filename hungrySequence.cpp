#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e7 + 1;
bool numbers[Nmax] = {true, true};

void sieve(int n){
    int cont = 0;
    for(int i = 0; i <= Nmax; i++){
        if(!numbers[i]){
            printf("%d ", i);
            cont++;
            for(int j = i * 2; j <= Nmax; j += i)
                    numbers[j] = true;
        }
        if(cont == n)
            break;
    }    
    printf("\n");
}   

int main(){
    int n;
    scanf("%d", &n);
    sieve(n);
    return 0;
}