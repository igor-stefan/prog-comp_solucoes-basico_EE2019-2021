#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x = 0, y = 0, z = 0, temp;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &temp);
        x += temp;
        scanf("%d", &temp);
        y += temp;
        scanf("%d", &temp);
        z += temp;
    }
    if(z or y or x)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}