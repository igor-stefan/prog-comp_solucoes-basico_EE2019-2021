#include <bits/stdc++.h>

using namespace std;

int main(){
    string a;
    while(cin >> a){
        if(a == "Z")
            break;
        vector<string> puzzle(5);
        puzzle[0] = a;
        for(int i = 1; i < 5; i++){
            cin >> a;
            puzzle[i] = a;
        }
        cin >> a;
        
    }


    return 0;
}