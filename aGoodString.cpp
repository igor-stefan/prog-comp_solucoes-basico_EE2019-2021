#include <bits/stdc++.h>

using namespace std;

int goodString(string s, int n, int c){
    if(n == 1){
        if(s[0] == c)
            return 0;
        return 1;
    }
    string right(s.begin(), s.begin() + n / 2);
    string left(s.begin() + n / 2, s.end());
    int c_right = 0, c_left = 0;
    
    for(auto& x: right)
        c_left += x != c;
    for(auto& x: left)
        c_right += x != c;

   return min(
        goodString(left, n / 2, c + 1) + c_left,
        goodString(right, n / 2, c + 1) + c_right
        );
}

int main() {
    int t, n;
    string s;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n >> s;
        cout << goodString(s, n, 'a') << endl;
    }

    return 0;
}