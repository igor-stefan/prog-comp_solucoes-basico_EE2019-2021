#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if(abs(x2 - x1) == abs(y2 - y1))
        printf("%d %d %d %d\n", x1, y2, x2, y1);
    else if(x1 == x2)
        printf("%d %d %d %d\n", y1 - y2 + x1, y1, y1 - y2 + x2, y2);
    else if(y1 == y2)
        printf("%d %d %d %d\n", x2, x2 - x1 + y2, x1, x2 - x1 + y1);
    else
        printf("-1\n");
    return 0;
}