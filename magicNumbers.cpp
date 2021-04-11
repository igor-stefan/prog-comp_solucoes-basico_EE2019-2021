#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    cin >> n;
    for(int i = 0; i< n.size(); i++){
        if(n[i] != '4'){
            if(n[i] != '1'){
                printf("NO\n");
                return 0;
            }
        }
        if(n[i] == '4')
            if(i >= 2){
                if(n[i - 1] != '1')
                    if(n[i - 2] != '1'){
                        printf("NO\n");
                        return 0;
                    }
            }
            else if(i >= 1){
                if(n[i - 1] != '1')
                    if(n[i - 1] != '4'){
                    printf("NO\n");
                    return 0;
                    }
            }
            else{
                printf("NO\n");
                    return 0;
            }
    }
    printf("YES\n");
    return 0;
}