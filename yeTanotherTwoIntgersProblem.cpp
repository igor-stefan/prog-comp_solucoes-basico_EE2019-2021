#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 3;


int query(int a, int b){
    int cont;
    int target = a - b;
    cont = target / 10;
    if(target % 10)
        cont++;
    return cont;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(b > a)
            swap(a,b);
        printf("%d\n", query(a,b));
    }
    return 0;
}