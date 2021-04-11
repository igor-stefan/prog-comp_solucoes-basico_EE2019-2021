#include <bits/stdc++.h>

using namespace std;

int words[27];

void removePair(){
    for(int i = 0; i < 27; i++){
        if(words[i] % 2 == 0)
            words[i]--;
            break;
    }
}
bool isPalindromic(int len, int even, int odd){
    if(len % 2){
        if(odd > 1)
            return false;
    }else
        if(even % 2)
            return false;
    return true;
}


void solve(int len, int odd, int even){
    int i = 1;
    while(!isPalindromic and len > 1){
        if(len & 1)
            pair--, odd++, len--, removePair();
        else
            
        i++
    }
}

int main(){
    int odd = 0, even = 0;
    string s;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++)
        words[s[i] - 'a']++;
    for(int i = 0; i < 27; i++)
        if(words[i] > 0){
            if(words[i] % 2)
                odd++;
            else
                even++;
        }
    solve(s.size(), odd, even);
    cout << "\nodd = " << odd << " even = " << even << '\n';
    return 0;
}