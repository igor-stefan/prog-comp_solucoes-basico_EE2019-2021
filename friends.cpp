#include <bits/stdc++.h>

using namespace std;

const int Nmax = 30 * 1e3 + 1; 
int parent[Nmax];

int find(int n){
    if(parent[n] < 0)
        return n;
    return parent[n] = find(parent[n]);
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
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            parent[i] = -1;
        for(int i = 1; i <= m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            merge(a, b);
        }
        for(int i = 1; i <= n; i++)
            find(i);
        int largest = INT_MIN;
        for(int i = 1; i <= n; i++)
            if(parent[i] < 0)
                largest = max(largest, -parent[i]);
        printf("%d\n", largest);
    }
    return 0;
}