#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 * 5 + 3;

int main(){
    int j, r;
    while(scanf("%d %d", &j, &r) == 2){
        vector<int> points(Nmax, 0);
        int maxp = INT_MIN;
        for(int i = 1; i <= j * r; i++){
            int temp;
            scanf("%d", &temp);
            points[i % j] += temp;
            maxp = max(maxp, points[i % j]);
        }
        int ans = 0;
        // for(int i = 0; i < j; i++)
        //     cout << points[i] << " ";
        // cout << "\n";  
        for(int i = 1; i < j; i++){
            if(points[i] == maxp)
                ans = i;
        }
        if(points[0] == maxp)
            ans = j;
        printf("%d\n", ans);
    }
    return 0;
}