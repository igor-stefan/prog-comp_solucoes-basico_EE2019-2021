#include <bits/stdc++.h>

using namespace std;

int main(){
    int l, maxValue = INT_MIN;
    string s, ans = "";
    map<string,int> occurrences;
    cin >> l >> s;
    for(int i = 0; i < l-1; i++){
        string x = s.substr(i, 2);
        occurrences[x]++;
        if(maxValue < occurrences[x]){
            maxValue = occurrences[x];
            ans = x;
        }
    }
    cout << ans << endl;
}