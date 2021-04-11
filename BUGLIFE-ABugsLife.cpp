#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3 * 3;
bool seen[Nmax];

bool dfs(int v, int color, vector<vector<int>>& adj, vector<bool>& vector_color){
    seen[v] = true;
    vector_color[v] = color;
    for(auto x : adj[v])
        if(!seen[x]){
            if(!dfs(x, color ^ 1, adj, vector_color))
                return false;
        }else{
            if(vector_color[v] == vector_color[x])
                return false;
        }
    return true;
}


int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        int n, m, a, b;
        scanf("%d %d", &n, &m);
        for(int k = 1; k <= n; k++)
            seen[k] = false;
        vector<vector<int>> adj(n + 1);
        vector<bool> color(n + 1);
        for(int j = 1; j <= m; j++)
            scanf("%d %d", &a, &b), adj[a].push_back(b), adj[b].push_back(a);
        printf("Scenario #%d:\n", i);
        bool flag = true;
        for(int k = 1; k <= n; k++)
            if(!seen[k]){ 
                if(!dfs(k, 1, adj, color)){
                    flag = false;
                    break;
                }
            }
        flag? printf("No suspicious bugs found!\n") : printf("Suspicious bugs found!\n"); 
        
    }
    return 0;
}