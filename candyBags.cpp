#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1, j = n * n; i <= n * n / 2; i++, j--)
        printf("%d %d\n", i, j);
    return 0;
}