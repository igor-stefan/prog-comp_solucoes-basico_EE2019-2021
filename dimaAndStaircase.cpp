#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 4;

long long ansQuery(const int a[], const int width, const int heigth, long long& actual_heigth){
    if(a[width] > actual_heigth)
        actual_heigth = a[width];
    long long ans = actual_heigth;
    actual_heigth += heigth;
    return ans;
}


int main(){
    int n, m, a[Nmax] = {0}, width, heigth;
    long long actual_heigth = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d %d", &width, &heigth);
        printf("%lld\n", ansQuery(a, width, heigth, actual_heigth));
    }
    return 0;
}