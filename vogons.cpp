#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e2 * 3 + 2;


set<pair<int, pair<int, int>>> val;
int a[Nmax][Nmax];
bool c[Nmax];
void destroy(int x, int y){
    c[y - 1] = true;
    c[y + 1] = true;
    a[x - 1][y] = -1;
    a[x + 1][y] = -1;
    a[x][y] = -1;
}

int main(){
    int n, m;
    while(cin >> n >> m ){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
                val.insert({a[i][j], {i, j}});
            }
        for(int j = 1; j <= m; j++)
            c[j] = false;
        int sum = 0;
        for(auto it = val.rbegin(); it != val.rend(); it++){
            if(!c[it->second.second])
                if(a[it->second.first][it->second.second] != -1){
                    sum += it->first;
                    destroy(it->second.first, it->second.second);
                }
        }
    printf("%d\n", sum);
    }
    return 0;
}
