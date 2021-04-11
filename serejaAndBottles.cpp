#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 2;
typedef vector<tuple<int, int, bool>> p;
p b(Nmax);

int main(){
    int n, cont = 0, a, c;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &a, &c), b[i] = make_tuple(a, c, false);
    for(int i = 1; i <= n; i++){
            int now = get<0>(b[i]);
        for(int j = 1; j <= n; j++){
            if(j != i){
                if(get<1>(b[j]) == now){
                    get<2>(b[i]) = true;
                    cont++;
                    break;
                }
            }
        }
    }
    printf("%d\n", n - cont);
    return 0;
}