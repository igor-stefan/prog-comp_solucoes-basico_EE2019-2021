#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3 + 50;

char tab[Nmax][Nmax];
int n, m, xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};


void dfs(int x, int y){
    tab[x][y] = 'x';
    for(int i = 0; i < 4; i++){
        int dx = x + xx[i], dy = y + yy[i];
        if(dx >= 1 and dx <= n and dy >= 1 and dy <= m)
            if(tab[dx][dy] == '.')
                dfs(dx, dy);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j<= m; j++)
            cin >> tab[i][j];
    int cont = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(tab[i][j] == '.'){
                cont++;
                dfs(i, j);
            }
        }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++)
    //         cout << tab[i][j];
    //     cout << "\n";
    // }
    cout << cont << "\n";

    return 0;
}