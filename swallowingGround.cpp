#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    while(scanf("%d", &t) == 1){
        for(int i = 1; i <= t; i++){
            if(i != 1)
                printf("\n");
            int x;
            scanf("%d", &x);
            int last = -1;
            bool flag = false;
            for(int j = 1; j <= x; j++){
                int a, b;
                scanf("%d %d", &a, &b);
                if(last == -1)
                    last = abs(a - b) + 1;
                else
                    if(abs(a - b) + 1 != last)
                        flag = true;
            }
            flag? printf("no\n") : printf("yes\n");
        }
    }
    return 0;
}