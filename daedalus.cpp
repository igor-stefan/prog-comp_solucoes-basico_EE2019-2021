#include <bits/stdc++.h>

using namespace std;

int cards[]= {1, 10, 100, 1000, 10000}; //5 cards

int main(){
    int n, m, c = 5;
    while(scanf("%d %d", &n, &m) == 2){
        int ans = 0;
        for(int i = 1; i <= m; i++){
            int b, a[n], sum = 0;
            scanf("%d", &b);
            for(int j = 0; j < n; j++){
                scanf("%d", &a[j]);
                if(j != 0)
                    sum += a[j];
            }
            // cout << "a[0] = " << a[0] <<"\n";
            // cout << "sum = " << sum << "\n";
            // cout << "sum + a[0] = " << sum + a[0] << "\n";
            // cout << "b = " << b << "\n";
            // for(int j = 0; j < n; j++)
            //     printf("%d ", a[j]);
            // printf("\n");
            int best_card = a[0];
            if(sum < b){
                if((sum + a[0]) > b){ //minimize a[0]
                    for(int j = 0; j < c; j++){
                        if(cards[j] > b - sum)
                            break;
                        if(cards[j] <= b - sum)
                            best_card = cards[j];
                    }
                    if(best_card != a[0])
                        ans += best_card;
                }
                else{ //maximize a[0]
                    for(int j = 0; j < c; j++){
                        if(sum + cards[j] > b)
                            break;
                        best_card = cards[j];
                    };
                    if(best_card != a[0])
                        ans += best_card - a[0];
                }
            } 
        }
        printf("%d\n", ans);
    }
    return 0;
}