#include <bits/stdc++.h>

using namespace std;

const int Nmax = 3 * 1e5 + 4;
const int treeMax = 5 * Nmax + 2;

int tree[treeMax], a[Nmax], ans[Nmax];

void build(int node, int l, int r){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * node, l, m);
    build(2 * node + 1, m + 1, r);
    tree[node] = 1;
}

void make_update(int node, int l, int r, int ql, int qr, int val){
    if(r < ql or l > qr or tree[node] == 0)
        return;
    if(l == r){
        if(l != val){
            tree[node] = 0;
            ans[l] = val;
        }
        return;
    }
    int m = (l + r) / 2;
    make_update(2 * node, l, m, ql, qr, val);
    make_update(2 * node + 1, m + 1, r, ql, qr, val);
    tree[node] = tree[2 * node] or tree[2 * node + 1];
}

int main(){
    int n, m, l, r, x;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        a[i] = i;
    build(1, 1, n);
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &l, &r, &x);
        make_update(1, 1, n, l, r, x);
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");


    return 0;
}