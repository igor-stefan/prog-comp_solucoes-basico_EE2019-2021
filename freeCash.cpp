#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 3;

int main(){
    int n, h[Nmax], m[Nmax];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &h[i], &m[i]);
    int actual_hour = h[1], actual_min = m[1], ans = INT_MIN;
    for(int i = 2; i <= n; i++){ 
        if(h[i] != actual_hour or actual_min != m[i]){
            actual_hour = h[i];
            actual_min = m[i];
        }
        else{
            int streak = 1;
            while(i <= n and actual_hour == h[i] and actual_min == m[i]){
                streak++; i++;
            }
            ans = max(streak, ans);
            i--;
        }
    }
    if(ans == INT_MIN)
        ans = 1;
    printf("%d\n", ans);
    return 0;
}