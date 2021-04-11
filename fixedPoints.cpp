#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 2;

int main(){
    int n, a[Nmax];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int fixed = 0;
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(a[i] == i)
            fixed++;
        else
            if(a[a[i]] == i)
                flag = true;
    }
    if(fixed == n)
        printf("%d\n", fixed);
    else
        flag? printf("%d\n", fixed + 2) : printf("%d\n", fixed + 1);
    return 0;
}