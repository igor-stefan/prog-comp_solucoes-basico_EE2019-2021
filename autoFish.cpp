#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, k = 0;
    scanf("%d", &n);
    for(int i = 0; i < n + 2; i++){
        if(i > 1)
            if(k++ >= 1)
                printf("\n");
        string linha;
        int bait = 0, fish = 0, cont = 0, op = 0, exito = 0;
        while(getline(cin, linha) and linha != ""){
            cont++;
            if(linha == "fish"){
                if(fish == 0 and bait >= 1)
                    bait--, fish++, cont = 0;
                else{
                    // cout << "cont = " << cont << " exito = " << exito << "\n";
                    if(bait >= 1)
                        exito++;
                    if((exito == 3 and cont >= 3 and bait >= 1) and (cont >= 7 and bait >= 1))
                        fish++, bait--, cont = 0, exito = 0;
                }
            }
            else if(linha == "bait"){
                // cout << "bait = " << bait << " op = " << op << "\n";
                if(++op == 2){
                    bait++;
                    op = 0;
                }
                if(bait >= 3){
                    bait = 3;
                    op = 0;
                }
                // cout << "bait if = " <<  bait << "\n";
            }
        }
        if(i > 1)
            printf("%d\n", fish);
    }

    return 0;
}