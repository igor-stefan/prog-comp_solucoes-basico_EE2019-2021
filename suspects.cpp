#include <bits/stdc++.h>

using namespace std;

const int Nmax = 3 * 1e4 + 2;

vector<vector<int>> adj;
int parent[Nmax];

int find(int n){
    if(parent[n] < 0)
        return n;
    return parent[n] = find(parent[n]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    if(parent[a] > parent[b])
        swap(a, b);
    parent[a] += parent[b];
    parent[b] = a;
}


int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) == 2 and (n or m)){
        for(int i = 0; i <= n; i++)
            parent[i] = -1;
        adj = vector<vector<int>>(n);
        for(int i = 0; i < m; i++){
            int k;
            scanf("%d", &k);
            for(int j = 0; j < k; j++){
                int a;
                scanf("%d", &a);
                adj[i].push_back(a);
            }
        }
        vector<vector<int>> pessoas(n);
        for(int i = 0; i < m; i++){
            for(int j = 1; j < (int)adj[i].size(); j++)
                merge(adj[i][j], adj[i][0]);
        }
        // for(int i = 0; i < n; i++)
            // cout << i << " - " << parent[i] << "\n";
        printf("%d\n", -parent[find(0)]);
    }
    return 0;
}
