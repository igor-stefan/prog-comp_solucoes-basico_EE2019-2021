#include <bits/stdc++.h>

using namespace std;

int main (){
   vector<int> myV(11);
    for(int i = 0; i <= 10; i++){
        myV[i] = 'a' + i;
    }
    vector<int>::iterator it;
    for(it = myV.begin(); it != myV.end(); it++)
        cout << *it  << " : " << *it << endl;

    return 0;
}