#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, c, cont = 0;
    while(scanf("%d %d %d", &n, &m, &c) == 3 and n and m and c){
        bool state[n + 1];
        for(int i = 1; i <= n; i++)
            state[i] = false;
        int ci[n + 1];
        for(int i = 1; i <= n; i++)
            scanf("%d", &ci[i]);
        int cv = 0, max_cv = INT_MIN;
        bool flag = false;
        printf("Sequence %d\n", ++cont);
        for(int j = 1; j <= m; j++){
            int temp;
            scanf("%d", &temp);
            state[temp] = !state[temp];
            state[temp] ? cv += ci[temp] : cv -= ci[temp];
            if(cv > c)
                flag = true;
            max_cv = max(max_cv, cv);
        }
        if(flag)
            printf("Fuse was blown.\n\n");
        else
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", max_cv);
    }
    return 0;
}