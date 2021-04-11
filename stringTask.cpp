#include <bits/stdc++.h>

using namespace std;

char vowels[] = {'a', 'e', 'i', 'y', 'o', 'u', 'A', 'E', 'I', 'Y', 'O', 'U'};
const int Nmax = 1e2 + 5;

bool isVowel(const char a){
    for(int i = 0; i < 12; i++)
        if(a == vowels[i])
            return true;
    return false;
}

int main(){
    char a[Nmax];
    vector<char> ans;
    cin >> (a + 1);
    for(int i = 1; i <= strlen(a + 1); i++){
        if(!isVowel(a[i])){
            ans.push_back('.');
            ans.push_back(tolower(a[i]));
        }
    }
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i];
    printf("\n");
    return 0;
}