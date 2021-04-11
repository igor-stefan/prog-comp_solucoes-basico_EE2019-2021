#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 3;

// int board[Nmax][Nmax];
bool board[Nmax][Nmax];

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool isPossibleUp(int n, int m, int i, int j){
    if(i + dy[0] >= 1 and i + dy[0] <= n and !board[i + dy[0]][j])
        return true;
    return false;
}
bool isPossibleDown(int n, int m, int i, int j){
    if(i + dy[2] >= 1 and i + dy[2] <= n and !board[i + dy[0]][j])
        return true;
    return false;
}
bool isPossibleRight(int n, int m, int i, int j){
    if(j + dx[1] >= 1 and j + dx[1] <= m and !board[i][j + dx[0]])
        return true;
    return false;
}
bool isPossibleLeft(int n, int m, int i, int j){
    if(j + dx[3] >= 1 and j + dx[3] <= m and !board[i][j + dx[3]])
        return true;
    return false;
}


void solve(int n, int m, int j, int i, int& cont){
    while(isPossibleUp(n, m, i, j)){
        i--;
        printf("%d %d\n", i, j);
        board[i][j] = true;
        cont++;
    }
    while(isPossibleDown(n, m, i, j)){
        i++;
        printf("%d %d\n", i, j);
        board[i][j] = true;
        cont++;
    }
    while(isPossibleRight(n, m, i, j)){
        j++;
        printf("%d %d\n", i, j);
        board[i][j] = true;
        cont++;
    }
    while(isPossibleLeft(n, m, i, j)){
        j--; 
        printf("%d %d\n", i, j);
        board[i][j] = true;
        cont++;
    }
    if(cont == n * m)
        return;
    for(int k = 1; k <= m; k++)
        if(!board[i][k])
            j = k;
    solve(n, m, j, i, cont);
}


int main() {
    int n, m, sx, sy, cont = 1;
    scanf("%d %d %d %d", &n, &m, &sx, &sy);
    board[sx][sy] = true;
    printf("%d %d\n", sx, sy);
    solve(n, m, sx, sy, cont);
    return 0;
}