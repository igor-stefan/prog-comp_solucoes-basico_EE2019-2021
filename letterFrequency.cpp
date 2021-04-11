#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    scanf("%d", &k);
    // cout << k << "\n";
    getchar();
    while(k--){
        map<char, int> freq;
        string a;
        int max_n = INT_MIN;
        getline(cin, a);
        // cout << a << "\n";
        for(int i = 0; i < (int)a.length(); i++){
            a[i] = ::tolower(a[i]);
            if((a[i] >= 'A' and a[i] <= 'Z') or (a[i] >= 'a' and a[i] <= 'z')){
                freq[a[i]]++;
                max_n = max(max_n, freq[a[i]]);
            }
        }
        // cout <<"max_n = " << max_n << "\n";
        for(auto x = freq.begin(); x != freq.end(); x++){
            // cout << x -> first << " " << x -> second << " \n";
            if(x -> second == max_n)
                cout << x -> first;
        }
        cout << "\n";
    }
    return 0;
}