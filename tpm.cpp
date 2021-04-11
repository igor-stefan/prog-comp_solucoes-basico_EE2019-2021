#include <bits/stdc++.h>

using namespace std;

int main () {
    int t, x, y, z;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d %d %d", &x, &y, &z);
        if(x == y and z <= x)
            printf("YES\n%d %d %d\n", x, z--, z);
        else if(x == z and y <= x)
            printf("YES\n%d %d %d\n", x, y--, y);
        else if(z == y and x <= z)
            printf("YES\n%d %d %d\n", y, x--, x);
        else   
            printf("NO\n");
    }
    return 0;
}