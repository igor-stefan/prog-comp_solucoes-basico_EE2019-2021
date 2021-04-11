#include <bits/stdc++.h>

using namespace std;

double kiss(int i, long long bit_mask, int ans){
    if(i < 0)
        return __builtin_popcount(bit_mask) == ans;
    return kiss(i - 1, bit_mask, ans) + kiss(i - 1, bit_mask | (1 << i), ans);
}

int main(){
    int pos = 0, question = 0;
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++)
        if(s1[i] == '+')
            pos += 1;
    for(int i = 0; i < s2.size(); i++){
        question += (s2[i] == '?');
        pos -= (s2[i] == '+');
    }
    printf("%.10f\n", kiss(question - 1, 0, pos) / (1 << question));
    return 0;
}