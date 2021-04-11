#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3 + 4;

vector<set<int>> adj;

bool find(int a, int b){
    for(int x : adj[a])
        if(x == b)
            return true;
    return false;
}

int main(){
    int n, m, a, b, q;
    scanf("%d %d", &n, &m);
    adj = vector<set<int>>(n + 1);
    for(int i = 1; i <= m; i++)
        scanf("%d %d", &a, &b), adj[a].insert(b), adj[b].insert(a);
    scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        int type;
        scanf("%d", &type);
        if(type){
            scanf("%d", &a);
            printf("%d\n", (int)adj[a].size());
        }
        else{
           scanf("%d %d", &a, &b);
            if(find(a, b))
                printf("S\n");
            else
                printf("N\n");
        }
    }
    return 0;
}