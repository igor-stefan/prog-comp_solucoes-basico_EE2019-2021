#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e5 + 4;
int solve(int a, int b, vector<vector<vector<int>>> v){
    int ans = 0;
    for(int i = 1; i <= v.size() - 1; i++)
        for(int j = 0; j < v[i].size(); j++)
            if(v[i][j] == a){
                for(auto x : a)
                    if(x == b)
                        ans++;
            }
    return ans;
}


int main(){
    int n, m, a, b, c, q;
    scanf("%d %d", &n, &m);
    vector<vector<vector<int>>> adj(m + 2);
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &a, &b, &c);
        adj[c][a].push_back(b);
        adj[c][b].push_back(a);
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", solve(a, b, adj));
    }
    return 0;
}