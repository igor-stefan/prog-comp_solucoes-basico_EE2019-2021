#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    if(a.size() != b.size()){
        printf("NO\n");
        return 0;
    }
    else{
        int dif = 0, i;
        pair<int, int> indexes;
        for(i = 0; i <= a.size(); i++){
            if(a[i] != b[i]){
                indexes.first = i;
                break;
            }
        }
        for(i = i + 1; i <= a.size(); i++){
            if(a[i] != b[i]){
                indexes.second = i;
                break;
            }
        }
        swap(a[indexes.first], a[indexes.second]);
        a == b ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}