#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) == 2){
        int cont = 0;
        for(int i = 1; i <= n; i++){
            int a;
            bool flag = true;
            for(int j = 1; j <= m; j++){
                scanf("%d", &a);
                if(a == 0)
                    flag = false;
            }
            if(flag)
                cont++;
        }
        printf("%d\n", cont);
    }
    return 0;
}
