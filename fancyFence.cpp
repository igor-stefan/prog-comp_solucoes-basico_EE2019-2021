#include <bits/stdc++.h>

using namespace std;

void isPossible(int val){
    if(360 % (180 - val))
        printf("NO\n");
    else
        printf("YES\n");
}

int main(){
    int t, val;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &val);
        isPossible(val);
    }
    return 0;
}