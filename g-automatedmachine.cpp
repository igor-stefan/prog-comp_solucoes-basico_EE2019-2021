#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,d,e,f,g,h,i,j;
    while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &e) == 5){
        scanf("%d %d %d %d %d", &f, &g, &h, &i, &j);
            if(abs(a-f) != 1 or abs(b-g) != 1 or abs(c - h) != 1 or abs(d - i) != 1 or abs(e-j) != 1)
                printf("N\n");
            else
                printf("Y\n");
    }
    return 0;
}
