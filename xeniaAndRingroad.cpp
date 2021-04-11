#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;

long long ringRoadTasks(int a[], int house, int n, int tasks){
    long long ans = 0;
    for(int i = 1; i <= tasks; i++){
        if(a[i] == house)
            continue;
        else if(a[i] > house){
            ans += a[i] - house;
            house = a[i];
        }
        else{
            ans += n - house + a[i];
            house = a[i];
        }
    }
    return ans;
}

int main(){
    int n, m, a[Nmax];
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    printf("%lld\n", ringRoadTasks(a, 1, n, m));
    return 0;
}