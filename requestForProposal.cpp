#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, p, cont = 0;
    while(scanf("%d %d", &n, &p) == 2 and n and p){
        if(cont != 0)
            printf("\n");
        getchar();
        for(int i = 1; i <= n; i++){
            string a;
            getline(cin, a);
        }
        string name;
        double priceBest = INT_MAX;
        int rMax = INT_MIN;
        for(int i = 0; i < p; i++){
            string now;
            double price;
            int r;
            getline(cin, now);
            scanf("%lf %d", &price, &r);
            getchar();
            for(int j = 0; j < r; j++){
                string temp;
                getline(cin, temp);
            }
            if(r > rMax){
                name = now;
                priceBest = price;
                rMax = r;
            }
            else if(r == rMax){
                if(price < priceBest){
                    name = now;
                    priceBest = price;
                }
            } 
        }
        printf("RFP #%d\n", ++cont);
        cout << name << "\n";
    }
    return 0;
}