#include <bits/stdc++.h>

using namespace std;

const int Nmax = 10 + 1;

int main(){
    int r, c;
    char a[Nmax][Nmax];
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            cin >> a[i][j];
            
    for(int i = 1; i <= r; i++){
        bool flag = false;
        for(int j = 1; j <= c; j++)
            if(a[i][j] == 'S'){
                flag = true;
                break;
            }
        if(!flag)
            for(int j = 1; j <= c; j++)
                a[i][j] = 'E';
    }

   for(int j = 1; j <= c; j++){
        bool flag = false;
        for(int i = 1; i <= r; i++)
            if(a[i][j] == 'S'){
                flag = true;
                break;
            }
        if(!flag)
            for(int i = 1; i <= r; i++)
                a[i][j] = 'E';
    }
    int ans = 0;
    for(int i = 1; i <= r; i++ )
        for(int j = 1; j <= c; j++)
            if(a[i][j] == 'E')
                ++ans;
    printf("%d\n", ans);

    return 0;
}