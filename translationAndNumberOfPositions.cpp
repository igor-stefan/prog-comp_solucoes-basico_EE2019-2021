#include <bits/stdc++.h>

using namespace std;

int main(){
    // string a, b;
    // cin >> a >> b;
    // reverse(b.begin(), b.end());
    // for(int i = 0; i < b.size(); i++)
    //     if(b[i] != a[i]){
    //         printf("NO\n");
    //         return 0;
    //     }
    // printf("YES\n");

    int n, a, b, cont = 0;
    scanf("%d %d %d",&n, &a, &b);
    for(int i = n; i >= n - b and i >= a + 1; i--)
        cont++;
    printf("%d\n", cont);

    return 0;
}