#include <bits/stdc++.h>

using namespace std;

const int Nmax = 10 + 1;
const int dx[] = {0, 1, 0, -1};
const int dy[] ={1, 0, -1, 0};
char a[Nmax][Nmax];

void eat_pig(int i, int j, int& cont){
    for(int k = 0; k < 4; k++){
        int d_x = j + dx[k];
        int d_y = i + dy[k];
        if(a[d_y][d_x] == 'P'){
            a[d_y][d_x] = '.';
            cont++;
            break;
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i <= Nmax; i++){
        for(int j = 0; j <= Nmax; j++){
            if(i == 0 || i > n)
                a[i][j] = '.';
            else if(j == 0 || j > m)
                 a[i][j] = '.';
            else
                cin >> a[i][j];
        }
    }

    int cont = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] == 'W')
                eat_pig(i, j, cont);
    printf("%d\n", cont);
    
    // for(int i = 0; i <= Nmax; i++){
    //     for(int j = 0; j <= Nmax; j++){ 
    //         cout << a[i][j] << " ";
    //     }
    //     printf("\n");
    // }
    return 0;
}
