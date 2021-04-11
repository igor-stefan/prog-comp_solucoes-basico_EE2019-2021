#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 4;

int m[Nmax][Nmax];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};


bool isPossible(int y, int x, int q, int n){
    if(x < 1 or y < 1 or y > n or x > n or m[y][x] <= q)
        return false;
    return true;
}

int max_Collected(int n, int k, int a, int b, int penny, int ans){
    for(int i = 0; i < 4; i++)
        if(isPossible(a + dy[i], b + dx[i], penny, n))
            ans = max(ans + penny, max_Collected(n, k, a + dy[i], b + dx[i], m[a + dy[i]][b + dx[i]], ans));
    return ans;
}

int main(){
    int cases;
    string a;
    scanf("%d", &cases);
    for(int i = 1; i <= cases; i++){
        if(i > 1)
            printf("\n");
        int n, k;
        getline(cin, a);
        scanf("%d %d", &n, &k);
        for(int j = 1; j <= n; j++)
            for(int p = 1; p <= n; p++)
                scanf("%d", &m[j][p]);
        printf("%d\n", max_Collected(n, k, 1, 1, m[1][1], 0));

    }
    return 0;
}