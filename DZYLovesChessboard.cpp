#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 3;

int main(){
    int n, m;
    string s;
    char a[Nmax][Nmax];
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        cin >> (a[i] + 1);
        for(int j = 1; j <= m; j++)
            if(a[i][j] == '.'){
                if((i + j) & 1)
                    a[i][j] = 'B';
                else
                    a[i][j] = 'W';
            }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            printf("%c", a[i][j]);
        printf("\n");
    }
    return 0;
}