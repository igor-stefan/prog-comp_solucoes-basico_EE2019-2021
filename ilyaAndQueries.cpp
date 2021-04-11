#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 2;

int rep[Nmax];

int query(int left, int right){
    return rep[right] - rep[left];
}

int main(){
    string a;
    int l, r, m;
    cin >> a;
    scanf("%d", &m);
    for(int i = 1; i <= (int)a.size() - 1; i++)
        if(a[i] == a[i - 1])
            rep[i + 1] = 1 + rep[i];
        else
            rep[i + 1] = rep[i];
  
    for(int i = 1; i <= m; i++)
        scanf("%d %d", &l, &r), printf("%d\n", query(l, r));
    return 0;
}