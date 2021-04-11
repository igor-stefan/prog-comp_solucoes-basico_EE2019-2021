#include <bits/stdc++.h>

using namespace std;

const int n = 6;

int beautifyMatrix(pair<int, int> home){
    return abs(home.first - 3) + abs(home.second - 3);
}


int main(){
    pair<int, int> home;
    int a[n][n];
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j]){
                home = make_pair(i, j);
                break;
            }
        }
        printf("%d\n", beautifyMatrix(home));
    return 0;
}