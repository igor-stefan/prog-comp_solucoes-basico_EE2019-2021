#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first < b.first)
        return true;
    if(a.first == b.first)
        if(a.second > b.second)
            return true;
    return false;
}

void isPossibleKillDragons(int s, int n, vector<pair<int, int>> xy){
    int killed = 0;
    sort(xy.begin(), xy.end(), comp);
    for(int i = 0; i < n; i++){
        if(s > xy[i].first){
            s += xy[i].second;
            killed++;
        }
        else
            break;
    }
    if(killed != n)
        printf("NO\n");
    else
        printf("YES\n");
}

int main(){
    int s, n, x, y;
    vector<pair<int, int>> xy;
    scanf("%d %d", &s, &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &x, &y);
        xy.push_back({x,y});
    }
    isPossibleKillDragons(s, n, xy);
    return 0;
}