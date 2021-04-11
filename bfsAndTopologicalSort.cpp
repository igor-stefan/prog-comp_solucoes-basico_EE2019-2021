#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 5;

int visited[Nmax], in[Nmax], dist[Nmax];
vector<vector<int>> adj(Nmax);
vector<int> topSorted;

void bfs(int node){
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int curr = q.front();
        cout << curr << "\n";
        q.pop();
        for(int x : adj[curr]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                dist[x]++;
            }
        }
    }
}

void dfs(int node){
    cout << node << "\n";
    visited[node] = true;
    for(int x : adj[node])
        if(!visited[x])
            dfs(x);
    
}

void topoSort(int n){
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(in[i] == 0)
            q.push(i);
    while(!q.empty()){
        int curr = q.front();
        topSorted.push_back(curr);
        q.pop();
        for(int x : adj[curr]){
            in[x]--;
            if(in[x] == 0)
                q.push(x);
        }
    }
    cout << "Topological Sort: ";
    for(int x : topSorted)
        cout << x << " ";
    cout << "\n";
}

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
        // scanf("%d %d", &a, &b), adj[a].push_back(b), adj[b].push_back(a);
        scanf("%d %d", &a, &b), adj[a].push_back(b), in[b]++; //directed graph
    topoSort(n);
    return 0;
}