#include <bits/stdc++.h>

using namespace std;

const int Amax = 2 * 1e2 + 2;
const int Vmax = 1e4 + 3;

void solve(const vector<vector<int>>& k, int a, int& cont){
    int maxN = INT_MIN;
    for(int i = 1; i <= a; i++)
        maxN = max(maxN, (int)k[i].size());
    printf("Teste %d\n", ++cont);
    for(int i = 1; i <= a; i++)
        if((int)k[i].size() == maxN)
            printf("%d ", i);
    printf("\n");
    return;
}

int main(){
    vector<vector<int>> k(Amax);
    int a = 1, v = 1, tempA, tempV, cont = 0;
    while(true){
        scanf("%d %d", &a, &v);
        if(a == 0 and v == 0)
            break;
        for(int i = 1; i <= v; i++){
            scanf("%d %d", &tempA, &tempV);
            k[tempA].push_back(tempV);
            k[tempV].push_back(tempA);
        }
    solve(k, a, cont);
    for(int i = 1; i <= a; i++)
        k[i].clear();
    k.clear();
    }
    return 0;
}
