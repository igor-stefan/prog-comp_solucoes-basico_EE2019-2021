#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 3;

typedef vector<pair<int, int>> oNomeQueEuQuiser;
oNomeQueEuQuiser lista;
void to_left(const int x, const int y){
    int xf = lista[x].first;
    int xs = lista[x].second;
    int yf = lista[y].first;
    int ys = lista[y].second;
    lista[x].first = yf;
    lista[x].second = y;
    lista[xs].first = xf;
    lista[xf].second = xs;
    lista[yf].second = x;
    lista[y].first = x;

}

void to_right(const int x, const int y){
    int xf = lista[x].first;
    int xs = lista[x].second;
    int yf = lista[y].first;
    int ys = lista[y].second;
    lista[x].first = y;
    lista[x].second = ys;
    lista[y].second = x;
    lista[ys].first = x;
    lista[xf].second = xs;
    lista[xs].first = xf;
}

void to_swap(const int x, const int y){
    swap(lista[x].first, lista[y].first);
    swap(lista[x].second, lista[y].second);
}

void to_reverse(int n){
    for(int i = 1; i <= n; i++)
        swap(lista[i].first, lista[i].second);
}

int main(){
    int n, m, cont = 0;
    while(scanf("%d", &n) != EOF){
        scanf("%d", &m);
        lista = oNomeQueEuQuiser(n + 1);
        for(int i = 1; i <= n; i++)
            lista[i].first = i - 1, lista[i].second = i + 1;
        int type, x, y;
        for(int i = 1; i <= m; i++){
            scanf("%d", &type);
            if(type == 1)
                scanf("%d %d", &x, &y), to_left(x, y);
            else if(type == 2)
                scanf("%d %d", &x, &y), to_right(x, y);
            else if(type == 3)
                scanf("%d %d", &x, &y), to_swap(x, y);
            else
                to_reverse(n);
    }
            int k = 1;
            for(k = 1; k <= n; k++)
                if(lista[k].first == 0){
                    cout << k << " ";
                    break;
                }
            for(int j = 1; j <= n - 1; j++){
                cout << lista[k].second << " ";
                k = lista[k].second;
            }
            cout << "\n"; 
        // long long sum = 0;
        // for(int i = 1; i<= n; i += 2)
        //     if(lista[i].first % 2 == 0 and lista[i].second % 2 == 0)
        //         sum += i;
        // printf("Case %d: %lld\n",++cont, sum);
    }
    return 0;
}