#include<bits/stdc++.h>

using namespace std;

const int Nmax = 27;
vector<set<int>> adj;
bool visited[Nmax];

void dfs(int node, set<char>& ans){
    visited[node] = true;
    char a = node + 'a' - 1;
    ans.insert(a);
    for(int x : adj[node])
        if(!visited[x])
            dfs(x, ans);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= Nmax; k++)
            visited[k] = false;
        int a, b;
        scanf("%d %d", &a, &b);
        adj = vector<set<int>>(a + 1);
        for(int j = 1; j <= b; j++){
            char p, q;
            cin >> p >> q;
            int x = p - 'a' + 1;
            int y = q - 'a' + 1;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        int cont = 0;
        printf("Case #%d:\n", i);
        for(int j = 1; j <= a; j++){
            if(!visited[j]){
                set<char> ans;
                cont++;
                dfs(j, ans);
                for(auto&x : ans)
                    printf("%c,", x);
                printf("\n");
            }
        }
        printf("%d connected components\n\n", cont);
    }
    return 0;
}