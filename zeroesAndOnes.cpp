#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    int i, j, cont = 0;
    while(cin >> a){
        int t;
        scanf("%d", &t);
        printf("Case %d:\n", ++cont);
        while(t--){
            scanf("%d %d", &i, &j);
            if(i > j)
                swap(i, j);
            bool flag = true;
            for(int k = i; k <= j; k++)
                if(a[k] != a[i]){
                    flag = false;
                    break;
                }
            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
