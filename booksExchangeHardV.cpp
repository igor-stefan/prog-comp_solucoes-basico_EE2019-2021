#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e5 + 4;
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
        swap(a,b);
    parent[a] += parent[b];
    parent[b] = a;
}   

int main(){
    int q, n;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        scanf("%d", &n);
        int a[n + 2];
        for(int k = 1; k <= n; k++)
            parent[k] = -1;
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[j]);
        for(int j = 1; j <= n; j++)
            merge(j, a[j]);
        for(int j = 1; j <= n; j++){
            find(j);
            if(parent[j] < 0)
                cout << -parent[j];
            else
                cout << -parent[parent[j]];
            if(j != n)
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}