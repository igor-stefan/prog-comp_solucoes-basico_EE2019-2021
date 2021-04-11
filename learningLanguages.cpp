#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 3;
const int mod = 1e9 + 7;
int parent[Nmax];

int find(int k){
    if(parent[k] < 0)
        return k;
    return parent[k] = find(parent[k]);
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
    int n, m, a, k, noSpeak = 0;
    scanf("%d %d", &n, &m);
    vector<vector<int>> speakers(m + 2);
    for(int i = 1; i <= n; i++)
        parent[i] = -1;
    for(int i = 1; i <= n; i++){
        scanf("%d", &k);
        if(k == 0)
            noSpeak++;
        for(int j = 1; j <= k; j++){
            scanf("%d", &a);
            speakers[a].push_back(i);
        }
    }
    for(int i = 1; i <= m; i++){
        if(speakers[i].size() <= 1)
            continue;
        for(int j = 0; j < speakers[i].size() - 1; j++)
            merge(speakers[i][j], speakers[i][j + 1]);
    }
    if(noSpeak == n)
        printf("%d\n", noSpeak);
    else{
        int ans = -1;
        for(int i = 1; i <= n; i++)
            if(parent[i] < 0)
                ans++;
        printf("%d\n", ans);
    }
    return 0;
}