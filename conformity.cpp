#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    while(scanf("%d", &k) == 1 and k){
        map<tuple<int, int, int, int, int>, int> comb;
        int max_comb = INT_MIN;
        tuple<int, int, int, int, int> t;
        for(int i = 1; i <= k; i++){
                int a[5];
                scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);
                sort(a, a + 5);
                t = make_tuple(a[0], a[1], a[2], a[3], a[4]);
            max_comb = max(++comb[t], max_comb);
        }
        int ans = 0;
        for(auto it = comb.begin(); it != comb.end(); it++){
            // cout << get<0>(it->first) << " " << get<1>(it->first) << " " << get<2>(it->first) << " "
            // << get<3>(it->first) << " "  << get<4>(it->first) << " = " << it -> second << "\n";
            if(it -> second == max_comb)
                ans += max_comb;
        }
        printf("%d\n", ans);
    }
    return 0;
}