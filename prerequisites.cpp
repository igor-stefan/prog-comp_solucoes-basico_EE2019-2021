#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, m;
    while(cin >> k >> m){
        string a[k];
        for(int i = 0; i < k; i++)
            cin >> a[i];
        int total = 0;
        for(int i = 1; i <= m; i++){
            int c, r, req = 0;
            scanf("%d %d", &c, &r);
            for(int j = 1; j <= c; j++){
                string temp;
                cin >> temp;
                for(int p = 0; p < k; p++)
                    if(a[p] == temp){
                        req++;
                        break;
                    }
            }
            if(req >= r)
                total++;
        }
        if(total == m)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
