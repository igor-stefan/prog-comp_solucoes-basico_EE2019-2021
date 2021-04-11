#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string a;
    map<string, int> goals;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        cin >> a;
        goals[a]++;
        if(goals[a] > n / 2){
            cout << a << "\n";
            break;
        }
    }
    return 0;
}