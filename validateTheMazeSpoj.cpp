#include <bits/stdc++.h>

using namespace std;
const int Nmax = 20 + 2;
bool seen[Nmax][Nmax];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool isValid(char a[][Nmax], int x, int y, int n, int m){
    if(x < 1 or x > n or y < 1 or y > m)
        return false;
    if(seen[y][x] or a[y][x] == '#')
        return false;
    return true;
}

bool dfs(char a[][Nmax], int m, int n, int stx, int sty, int edx, int edy){
    seen[sty][stx] = true;
    if(stx == edx and sty == edy)
        return true;
    for(int i = 0; i < 4; i++){
        if(isValid(a, stx + dx[i], sty + dy[i], n, m))
            dfs(a, m, n, stx + dx[i], sty + dy[i], edx, edy);
    }
    return false;
}

bool verifyEdges(char a[][Nmax], int m, int n, int& stx, int& sty, int& edx, int& edy){
    int cont = 0;
    int i[] = {1, m};
    int j[] = {1, n};
    for(int k = 0; k < 2; k++){
        for(int h = 1; h <= n; h++)
            if(a[i[k]][h] == '.'){
                if(++cont == 1)
                    stx = h, sty = i[k];
                if(cont == 2)
                    edx = h, edy = i[k];
                if(cont > 2)
                    return false;
            }
        if(i[0] == i[1])
            break;
    }
            for(int k = 2; k <= m - 1; k++){
                for(int h = 0; h < 2; h++)
                    if(a[k][j[h]] == '.'){
                        if(++cont == 1)
                            stx = j[h], sty = k;
                        if(cont == 2)
                            edx = j[h], edy = k;
                        if(cont > 2)
                            return false;
                }
                if(j[0] == j[1])
                    break;
            }
    return cont == 2;
}


int main(){
    int t;
    scanf("%d", &t);
    for(int p = 1; p <= t; p++){
        int n, m;
        char a[Nmax][Nmax];
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
               cin >> a[i][j]; 
        int stx = 0, sty = 0, edx = 0, edy = 0;
        if(verifyEdges(a, m, n, stx, sty, edx, edy))
             if(dfs(a, m, n, stx, sty, edx, edy))
                printf("valid\n");
             else{
                 printf("invalid\n");
                 continue;
             }
         else
             printf("invalid\n");
    }
    return 0;
}