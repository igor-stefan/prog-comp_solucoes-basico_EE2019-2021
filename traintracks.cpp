#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    while(scanf("%d", &t) == 1){
        getchar();
        while(t--){
            string x;
            getline(cin, x);
            int m = 0, f = 0;
            for(int i = 0; i < (int)x.size(); i++){
                if(x[i] == 'M')
                    m++;
                else if(x[i] == 'F')
                    f++;
            }
            if(m == f and m > 1 and f > 1)
                printf("LOOP\n");
            else
                printf("NO LOOP\n");
        }
    }

    return 0;
}
