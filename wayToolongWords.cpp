#include <bits/stdc++.h>

using namespace std;

    int num;
    string a;
int main(){
    cin>>num;
    while(num--){
    cin>>a;
    int tam = a.length();
    if(tam>10){
        cout<<a.front()<<tam-2<<a.back()<<endl;
    }else{
        cout<<a<<endl;
    }    
    }
    return 0;
}