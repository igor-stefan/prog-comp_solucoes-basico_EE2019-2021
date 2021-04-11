#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e5 + 2;
bool seen[Nmax];
map<int, vector<int>> adj;
vector<vector<tuple<int, int, int>>> graph;
vector<tuple<int, int, int>> ans;

void dfs(int node, int& contagem){
    seen[node] = true;
    for(auto& x : graph[node]){
        int atual = get<1>(x); 
        if(!seen[atual]){
            ans.push_back(make_tuple(get<0>(x), atual, get<2>(x)));
            dfs(atual, ++contagem);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    graph.resize(n + 2);
    for(int i = 1; i <= n; i++){
        int a, b;
        scanf("%d", &a);
        while(a--){
            scanf("%d", &b);
            adj[b].push_back(i);
        }
    }
    printf("lista dos numeros:\n");
    for(auto it: adj){
        printf("%d: ",it.first);
        for(auto k : it.second)
            printf("%d ", k);
        printf("\n");
    }
    for(auto it = adj.begin(); it != adj.end(); it++){
        if(it->second.size() > 1){
            for(int i = 1; i < (int)it -> second.size(); i++){
                graph[it -> second[0]].push_back(make_tuple(it -> second[0], it -> second[i], it -> first)); 
            }
        }
    }
    printf("grafo formado: u v aresta(numero em comum):\n");
    for(int i = 1; i <= n; i++){
        printf("%d: ", i);
        for(auto k : graph[i]){
            printf("%d %d %d - ", get<0>(k), get<1>(k), get<2>(k));
        }
        printf("\n");
    }
    int cont = 1;
    int i = 1;
    while(graph[i].empty() and i <= n)
        i++;
    dfs(i, cont);
    if(cont == n)
        for(auto x : ans)
            printf("%d %d %d\n", get<0>(x), get<1>(x), get<2>(x));

    else
        printf("impossible\n"); 
    return 0;
}