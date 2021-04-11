#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0)
            break;
        string x;
        cin >> x;
        int lastR = INT_MAX;
        int lastD = INT_MAX;
        int minDist = INT_MAX;
        for(int i = 0; i < (int)x.size(); i++){
            if(x[i] == 'Z'){
                minDist = 0;
                break;
            }
            if(x[i] == 'R'){
                lastR = i;
                minDist = min(minDist, abs(lastR - lastD));
            }
            if(x[i] == 'D'){
                lastD = i;
                minDist = min(minDist, abs(lastD - lastR));
            }
        }
        cout << minDist << "\n";
    }
    return 0;
}