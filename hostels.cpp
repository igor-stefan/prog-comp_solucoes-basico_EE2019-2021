#include <bits/stdc++.h>

using namespace std;


int main(){
    string x;
    while(cin >> x){
        int cont = 0, maxK = INT_MIN, i = 0;
        for(; i < (int)x.size(); i++){
            if(x[i] == 'X'){
                maxK = max(maxK, cont - 1);
                cont = 0;
                break;
            }
            else
                cont++;
        }
        for(; i < (int)x.size(); i++){
            if(x[i] == 'X'){
                if(cont % 2)
                    maxK = max(maxK, cont / 2);
                else
                    maxK = max(maxK, (cont / 2) - 1);
                cont = 0;
            }
            else
                cont++;
        }
        maxK = max(maxK, cont - 1);
        printf("%d\n", maxK);
    }
    printf("\n");
    return 0;
}