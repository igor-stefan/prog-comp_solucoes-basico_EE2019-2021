#include<bits/stdc++.h>

using namespace std;

const int Nmax = 5 * 1e2 + 2;


map<int, pair<int,int>> func;


void troca(int a, int b){


}

void posicao(int a){

}

int main(){
    int n, m, j;
    while(cin >> n >> m >> j){
        for(int i = 1; i <= n; i++){
            scanf("%d", &temp);
            func[i].second = temp;
        }
        for(int i = 1; i <= m; i++){
            int x, y;
            scanf("%d %d", x, y);
        }
        for(int i = 1; i <= j; i++){
            char type;
            int a, b;
            scanf("%c", &type);
            if(type == 'T')
                scanf("%d %d", &a, &b), troca(a, b);
            else
                scanf("%d", &a), posicao(a); 
        }
    }

    return 0;
}