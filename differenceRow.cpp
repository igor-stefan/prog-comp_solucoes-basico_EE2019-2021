#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 5;

int main(){
    pair<int, int> maxElement = {INT_MIN, -1}, minElement{INT_MAX, -1};
    int n, a[Nmax];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d",& a[i]);
    for(int i = 1; i <= n; i++){
        if(maxElement.first < a[i]){
            maxElement.first = a[i];
            maxElement.second = i;
        }
        if(minElement.first > a[i]){
            minElement.first = a[i];
            minElement.second = i;
        }
    }
    a[maxElement.second] = -1e4;
    a[minElement.second] = -1e4;
    sort(a + 1, a + n + 1);
    printf("%d ", maxElement.first);
    for(int i = 3; i <= n; i++){
        printf("%d ",a[i]);
    }
    printf("%d\n", minElement.first);
    return 0;
}