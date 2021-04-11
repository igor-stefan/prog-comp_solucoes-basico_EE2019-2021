#include <bits/stdc++.h>

using namespace std;

bool compatible(char x, char y){
    if(x == '1' or (x == '2' and y == '1'))
        return true;
    return false;
}

int main(){
    string a, b;
    while(cin >> b >> a){
        int maxCont = INT_MIN;
        for(int i = 0; i < (int)b.size(); i++){
            if(compatible(a[0], b[i])){
                int j = 0, k = i;
                while(compatible(a[j], b[k]) and j < (int)a.size() and k < (int)b.size())
                    j++, k++;
                maxCont = max(maxCont, j);
            }
        }
        if(maxCont == (int)a.size())
            printf("%d\n", (int)b.size());
        else{
            int k = 0;
            for(int i = 0; i < maxCont; i++){
                if(compatible(a[i], b[(int)b.size() - maxCont + i]))
                    k++;
                else
                    break;
            }
            if(k == maxCont)
                printf("%d\n", (int)b.size() + (int)a.size() - k);
            else
                printf("%d\n", (int)b.size() + (int)a.size());
        }

    }

    return 0;
}