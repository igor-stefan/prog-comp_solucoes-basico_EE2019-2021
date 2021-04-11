#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e5 + 4;
bool visited[Nmax];
vector<vector<int>> good, bad;

void dfs(int v, vector<int>& vip, set<int>& bl){
    if(!visited[v]);
        vip.push_back(v);
    visited[v] = true;
    for(auto x : bad[v])
        bl.insert(x);
    for(auto x: good[v]){
        if(visited[x])
            continue;
        dfs(x, vip, bl);
    }
}

int main(){
    int n, k, a, b;
    scanf("%d %d", &n, &k);
    good = vector<vector<int>> (n + 2);
    bad = vector<vector<int>> (n + 2);
    for(int i = 1; i <= k; i++){
        scanf("%d %d", &a, &b);
        good[a].push_back(b);
        good[b].push_back(a);
    }
    scanf("%d", &k);
    for(int i = 1; i <= k; i++){
        scanf("%d %d", &a, &b);
        bad[a].push_back(b);
        bad[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i])
            continue;
        vector<int> vip;
        set<int> blacklist;
        dfs(i, vip, blacklist);
        bool flag = true;
        for(const auto& e : vip)
            if(blacklist.find(e) != blacklist.end()){
                flag = false;
                break;
            }
        if(flag)
            ans = max(ans, (int)vip.size());
    }
    printf("%d\n", ans);
    return 0;
}