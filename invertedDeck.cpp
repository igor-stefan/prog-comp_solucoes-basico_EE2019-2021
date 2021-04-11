#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e6 + 2;

int main(){
    int n, a[Nmax], copy[Nmax], temp;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &temp), a[i] = temp, copy[i] = temp;
    sort(copy + 1, copy + 1 + n);
    int first = 1;
    while(first <= n and a[first] == copy[first])
        first++;
    int second = n;
    while(second >= 1 and a[second] == copy[second])
        second--;
    if(second == 0 and first == n + 1){ //if the sequence is ordened
        printf("1 1\n");
        return 0;
    }
    reverse(a + first, a + second + 1);
    for(int i = 1; i <= n - 1; i++)
        if(a[i] > a[i + 1]){
            printf("impossible\n");
            return 0;
        }
    printf("%d %d\n", first, second);
    return 0;
}