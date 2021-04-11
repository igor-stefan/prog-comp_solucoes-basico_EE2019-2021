#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int Nmax = 1e5 + 2;
int parent[Nmax];
//solution without dsu
/* vector<vector<int>> adj;
bool seen[Nmax];

int dfs(int node, int& numOfComponents){
    seen[node] = true;
    for(int x : adj[node])
        if(!seen[x])
            dfs(x, ++numOfComponents);
    return numOfComponents;
}


void solve(int n){
    for(int i = 0; i <= n; i++)
        seen[i] = false;
    int cont = 0, size = 1;
    long long ans = 1;
    for(int i = 1; i <= n; i++)
        if(!seen[i]){
            ans *= dfs(i, size);
            ans %= mod;
            cont++;
            size = 1;
        }
    printf("%d %lld\n", cont, ans);

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, a, b;
        scanf("%d %d", &n, &m);
        adj = vector<vector<int>>(n + 1);
        for(int i = 1; i <= m; i ++)
            scanf("%d %d", &a, &b), adj[a].push_back(b), adj[b].push_back(a);
        solve(n);
    }

    return 0;
}
*/

//solution with dsu

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
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, a, b;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            parent[i] = -1;
        for(int i = 1; i <= m; i ++)
            scanf("%d %d", &a, &b), merge(a, b);
        int cont = 0;
        long long ans = 1;
        for(int i = 1; i <= n; i++)
            if(parent[i] < 0)
                cont++, ans *= -parent[i], ans %= mod;
        printf("%d %lld\n", cont, ans);
    }
    return 0;
}