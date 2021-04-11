#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e4 + 2; 

int in[Nmax];
vector<vector<int>> adj;
vector<int> ans;


void topoSort(int n){
    auto cmp = [](int left, int right) { return left > right; };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    for(int i = 1; i <= n; i++)
        if(in[i] == 0)
            q.push(i);
    while(!q.empty()){
        int curr = q.top();
        q.pop();
        ans.push_back(curr);
        for(int x : adj[curr]){
            in[x]--;
            if(in[x] == 0)
                q.push(x);
        }
    }
    if((int)ans.size() == n)
        for(int x : ans)
            printf("%d ", x);
    else
        printf("Sandro fails.");
    printf("\n");

}

int main(){
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    adj.reserve(n + 1);
    for(int i = 1; i <= m; i++)
        scanf("%d %d", &a, &b), adj[a].push_back(b), in[b]++;
    topoSort(n);
    return 0;
}