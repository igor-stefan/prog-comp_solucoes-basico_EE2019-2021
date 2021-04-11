#include <bits/stdc++.h>

using namespace std;

int parent[50 + 3];

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
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        parent[i] = -1;
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &a, &b);
        merge(a, b);
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        if(parent[i] < 0)
            ans += -parent[i] - 1;
    printf("%lld\n", 1LL * 1 << (ans));
    return 0;
}