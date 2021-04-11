#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 5;
int main(){
    string a;
    cin >> a;
    for(int i = 0; i < a.size(); i++)
        if(a[i] == 'H' or a[i] == 'Q' or a[i] == '9'){
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
    return 0;
}