#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string a[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday"};
    vector<pair<int, int>> dates = {{4, 4}, {5, 9}, {6, 6}, {7, 11}, {8, 8}, {9, 5}, {10, 10}, {11, 7}, {12, 12}};
    while(scanf("%d", &t) == 1){
        for(int i = 1; i <= t; i++){
            int d, m;
            scanf("%d %d", &m, &d);
            bool flag = false;
            for(int j = 0; j < 9; j++){ 
                if(m == dates[j].second){
                    if(d < dates[j].first)
                        cout << a[7 - ((dates[j].first - d) % 7)] << "\n";
                    else
                        cout << a[(d - dates[j].first) % 7] << "\n";
                    flag = true;
                    break;
                }
            }
            if(!flag){
                if(m == 2)
                    d += 31;
                if(m == 3)
                    d += 59;
                cout << a[7 - ((94 - d) % 7)] << "\n";
            }
        }
    }
    return 0;
}