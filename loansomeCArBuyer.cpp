#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, d;
    double p, q;
    while(scanf("%d %lf %lf %d", &m, &p, &q, &d) == 4){
        if(m < 0)
            break;
        vector<pair<int, double>> precos(d);
        int a;
        double b, val = q;
        for(int i = 0; i < d; i++){
            scanf("%d %lf", &a, &b);
            precos[i] = {a, b};    
        }
        double down = q / m;
        q += p;
        b = precos[0].second;
        q -= q * b;
        int cont = 0, k = 1;
        if(val > q){
            for(cont = 1; cont < m; cont++){
                if(k < d and cont == precos[k].first){
                    b = precos[k].second;
                    k++;
                }
                val -= down;
                q -= (q * b);
                if(val < q)
                    break;
                
            }
        }
        if(cont != 1)
            printf("%d months\n", cont);
        else
            printf("%d month\n", cont);
    }
    return 0;
}
