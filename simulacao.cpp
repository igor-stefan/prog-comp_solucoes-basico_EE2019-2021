#include <bits/stdc++.h>
#define f(a, b) for (int i = a; i < b; i++)
#define ff(a, b) for (int j = a; j < b; j++)
#define pb push_back
#define mp make_pair
#define TAM 55
#define pii pair<int, int>
using namespace std;

vector<char> aux(TAM, '.');
vector<vector<char>> grid(TAM, aux);
map<pii, pii> bump;
int preco_parede, n, m;
pii mov[4] = {mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)};
//direcoes    0 dir     1 cima     2 esq       3 baixo

int simu(int x, int y, int direcao, int lifetime){
    int pontos = 0, X, Y;
    while (lifetime > 0){
        X = x + mov[direcao].first; //nova posição x
        Y = y + mov[direcao].second; //nova posicao y
        // cout << "X = " << X << " Y = " << Y << "    lifetime = " << lifetime <<" \n";
            if (grid[X][Y] == 'w'){
                direcao = (direcao + 3) % 4; //atualiza nova direção
                if(preco_parede) //se o custo da parede nao é nulo
                    lifetime -= preco_parede; // tira da vida o custo da batida na parede
                else lifetime--; // se é nulo, tira apenas o movimento
            }
            else if (grid[X][Y] == 'b'){
                direcao = (direcao + 3) % 4; //atualiza nova direção
                int preco_bumper = bump[mp(X, Y)].second; //custo de vida ao acertar o bumper
                if(preco_bumper) //se o custo nao é nulo
                    lifetime -= preco_bumper; //tira o custo
                else lifetime--; //se é nulo, tira apenas um de vida pelo movimento
                pontos += bump[mp(X, Y)].first; //acrescenta os pontos do bumper
            }
            else
                x = X, y = Y, lifetime--; //atualiza posicao e tira um no tempo de vida
    }
    return pontos;
}

int main()
{
    int qtde_bumpers, x, y, value, cost, lifetime, direcao;
    cin >> n >> m >> preco_parede >> qtde_bumpers;
    f(0, m){
        grid[0][i] = 'w';
        grid[n - 1][i] = 'w';
    }
    f(0, n){
        grid[i][0] = 'w';
        grid[i][m - 1] = 'w';
    }
    f(0, qtde_bumpers)
    {
        cin >> x >> y >> value >> cost;
        x = n - x;
        grid[x][--y] = 'b';
        bump[mp(x, y)] = mp(value, cost);
    }    
    int soma = 0;
    while (cin >> x >> y >> direcao >> lifetime)
    {
        // cout << "bola " << ++cont << ":\n";
        x = n - x;
        // cout << "x = " << x << " y = " << y - 1 << " --> ";
        grid[x][y - 1] = 'x';
        cout<< "\n";
        f(0, n)
    {
        ff(0, m)
                cout
            << grid[i][j];
        cout << endl;
    }
        int p = simu(x, --y, direcao, lifetime);
        soma += p;
        cout << p << '\n';
        grid[x][y] = '.';
    }
    cout << soma << '\n';
}