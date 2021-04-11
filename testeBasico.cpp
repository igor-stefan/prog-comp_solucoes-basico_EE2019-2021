#include <bits/stdc++.h>
using namespace std;

int main(){
    string a = "hello";
    string b = "h";
    for(int i = 0; i < a.size(); i++ ){
            if(a[i] == b[i])
                cout << b[i] << " ";
    }
    printf("\n");
}