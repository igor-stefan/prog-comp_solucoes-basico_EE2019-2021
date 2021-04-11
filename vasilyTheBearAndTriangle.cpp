#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y, val;
    scanf("%d %d", &x, &y);
    val = abs(x) + abs(y);
    if(y > 0){
        if(x < 0)
            printf("%d 0 0 %d\n", -val, val);
        else
            printf("0 %d %d 0\n", val, val);
    }
    else{
        if(x < 0)
            printf("%d 0 0 %d\n", -val, -val);
        else
            printf("0 %d %d 0\n", -val, val);
    }

    return 0;
}