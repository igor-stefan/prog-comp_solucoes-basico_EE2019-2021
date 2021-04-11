#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 * 3;

void restoreRemix(char a[], const string b){
    int occ = 0;
    for(int i = 1; i <= strlen(a + 1); i++){
        if(a[i] == 'W' and a[i + 1] == 'U' and a[i + 2] == 'B'){
            while(true){
                if(a[i] == 'W' and a[i + 1] == 'U' and a[i + 2] == 'B' and i <= strlen(a + 1))
                    i += 3;
                else
                    break;
            }
        if(occ++)
            cout << " ";
        }
        else
            occ++;
        if(a[i] != '\0')
            cout << a[i]; 
    }
}


int main (){
    char a[Nmax];
    cin >> (a + 1);
    restoreRemix(a, "WUB");
    cout << "\n";
    return 0;
}