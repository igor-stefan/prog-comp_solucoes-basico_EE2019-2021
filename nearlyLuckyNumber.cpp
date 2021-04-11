#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    int cont = 0;
    cin >> n;
    for(int i = 0; i < n.size(); i++){
        if(n[i] == '4' || n[i] == '7')
            cont++;
    }
    if(cont == 4 || cont == 7)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}