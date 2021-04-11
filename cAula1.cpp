#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    vector<set<int>> adj(n);
    for(int i = 1; i <= m; i++)
        scanf("%d %d", &a, &b), adj[a].insert(b);
    for(int i = 0; i < n; i++){
        printf("%d: ", i);
        if(adj[i].empty())
            printf("\n");
        else{
            auto it = adj[i].rbegin();
            for(int k : adj[i])
                if(k == *it)
                    printf("%d", k);
                else
                    printf("%d ", k);
        }
    printf("\n");
    }
    return 0;
}