#include <bits/stdc++.h>

using namespace std;

const int Nmax = 30 * 1e3 + 1;

int rec(int n, int k) { 
    if (n == 1) 
        return 1; 
    else
        return (rec(n - 1, k) + k - 1) % n + 1; 
} 
  
int main(){
    int t, cont = 0;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        printf("Case %d: %d\n", ++cont, rec(n, m));
    }
    return 0;
}