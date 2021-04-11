#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e3 + 5;

vector<vector<int>> adj;
map <int, int> total_cost;
bool removed[Nmax];

int main(){
    int n, m, x, y;
    long long ans = 0;
    scanf("%d %d", &n, &m);
    int cost[n + 2];
    adj = vector<vector<int>> (n + 2);
    for(int i = 1; i <= n; i++)
        scanf("%d", &cost[i]);
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < adj[i].size(); j++)
            ans +=  1LL * min(cost[i], cost[adj[i][j]]);
    printf("%lld\n", ans / 2);
    return 0;
}