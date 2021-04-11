#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 3;

int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) == 2){
        if(a == 0)
            break;
        set<int> freqA, freqB;
        for(int i = 1; i <= a; i++){
            int temp;
            scanf("%d", & temp);
            freqA.insert(temp);
        }
       for(int i = 1; i <= b; i++){
            int temp;
            scanf("%d", & temp);
            freqB.insert(temp);
        }
        int k = 0, y = 0;
        for(auto& it: freqA)
            if(freqB.find(it) == freqB.end())
                k++;
        for(auto& it: freqB)
            if(freqA.find(it) == freqA.end())
                y++;
        if(y < k)
            swap(k, y);
        printf("%d\n", k);
    }
    return 0;
}