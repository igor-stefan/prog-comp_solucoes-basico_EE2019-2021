#include <bits/stdc++.h>

using namespace std;

int a[27];
int main(){
    int k;
    string s, ans = "";
    scanf("%d", &k);
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++)
        a[s[i] - 'a']++;
    for(int i = 0; i < 27; i++){
        if(a[i] % k){
            printf("-1\n");
            return 0;
        }
        for(int j = 1; j <= a[i] / k; j++)
            ans += i + 'a'; //ans receives the correspondent character
    }
    for(int i = 1; i <= k; i++)
        cout << ans;
    printf("\n");
}
