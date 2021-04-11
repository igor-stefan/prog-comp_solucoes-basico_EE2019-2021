#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 4;

bool visited[Nmax];

int main(){
    int n, s, t, a[Nmax];
    scanf("%d %d %d", &n, &s, &t);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int pos = s, ans = 0;
    while(pos != t){
        if(pos[visited]){
            ans = -1;
            break;
        }
        pos[visited] = true;
        ans++;
        pos = a[pos];
    }
    printf("%d\n", ans);

    return 0;
}