#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e3 + 5;

int main(){
    int n, a[Nmax];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int ans = 0, least_number_of_points, highest_number_of_points;
    least_number_of_points = highest_number_of_points = a[1];
    for(int i = 2; i <= n; i++){
        if(a[i] < least_number_of_points){
            ans++;
            least_number_of_points = a[i];
        }
        else if (a[i] > highest_number_of_points){
            ans++;
            highest_number_of_points = a[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}