#include <bits/stdc++.h>

using namespace std;

int find(vector<tuple<string, int, int, int, int, int, int, int, int>>& a, string b, int c){ 
    int i;
    for(i = 1; i <= c; i++){ 
        if(get<0>(a[i]) == b)
            break;
    }
    return i;
}

bool compare(const tuple <string, int, int, int, int, int, int, int, int> a, const tuple<string, int, int, int, int, int, int, int, int> b){
    string x = get<0>(a), y = get<0>(b);
    if(get<1>(a) == get<1>(b)){
        if(get<3>(a) == get<3>(b)){
            if(get<6>(a) == get<6>(b)){
                if(get<7>(a) == get<7>(b)){
                    if(get<2>(a) == get<2>(b)){
                        for(auto& v : x)
                            v = tolower(v);
                        for(auto& v : y)
                            v = tolower(v);
                        if(x == y){
                            return false;
                        }else
                            return x < y;
                    }else
                        return get<2>(a) < get<2>(b);
                }else
                    return get<7>(a) > get<7>(b);
            }else
                return get<6>(a) > get<6>(b);
        }else
            return get<3>(a) > get<3>(b);
    }else
        return get<1>(a) > get<1>(b);
    return false;
}

int main(){
    int k, m = 0;
    scanf("%d", &k);
    getchar();
    while(k--){
        string a;
        getline(cin, a);
        int t;
        scanf("%d", &t);
        vector<tuple<string, int, int, int, int, int, int, int, int>> teams(t + 1, make_tuple("", 0, 0, 0, 0, 0, 0, 0, 0));
                     //time, pontos, jogos, wins, empates, loses, saldo, gols marcados, gols sofridos 
        getchar();
        for(int i = 1; i <= t; i++){
            string team;
            getline(cin, team);
            get<0>(teams[i]) = team;
        }
        int g;
        scanf("%d", &g);
        getchar();
        for(int i = 1; i <= g; i++){
            string partida, time_a, time_b, ga, gb;
            int gols_a, gols_b;
            getline(cin, partida);
            int x = 0;
                while(partida[x] != '#')
                    time_a += partida[x++];
                while(partida[++x] != '@')
                    ga += partida[x];
                while(partida[++x] != '#')
                    gb += partida[x];
                while(++x != (int)partida.length())
                    time_b += partida[x];
                gols_a = stoi(ga);
                gols_b = stoi(gb);
                if(gols_a == gols_b){
                    auto p = find(teams, time_a, t);
                    get<1>(teams[p])++;
                    get<2>(teams[p])++;
                    get<4>(teams[p])++;
                    get<6>(teams[p]) += gols_a - gols_b;
                    get<7>(teams[p]) += gols_a;
                    get<8>(teams[p]) += gols_b;
                    auto q = find(teams, time_b, t);
                    get<1>(teams[q])++;
                    get<2>(teams[q])++;
                    get<4>(teams[q])++;
                    get<6>(teams[q]) += gols_b - gols_a;
                    get<7>(teams[q]) += gols_b;
                    get<8>(teams[q]) += gols_a;
                }
                else if(gols_a > gols_b){
                    auto p = find(teams, time_a, t);
                    get<1>(teams[p]) += 3;
                    get<2>(teams[p])++;
                    get<3>(teams[p])++;
                    get<6>(teams[p]) += gols_a - gols_b;
                    get<7>(teams[p]) += gols_a;
                    get<8>(teams[p]) += gols_b;
                    auto q = find(teams, time_b, t);
                    get<2>(teams[q])++;
                    get<5>(teams[q])++;
                    get<6>(teams[q]) += gols_b - gols_a;
                    get<7>(teams[q]) += gols_b;
                    get<8>(teams[q]) += gols_a;
                }else{
                    auto p = find(teams, time_a, t);
                    get<2>(teams[p])++;
                    get<5>(teams[p])++;
                    get<6>(teams[p]) += gols_a - gols_b;
                    get<7>(teams[p]) += gols_a;
                    get<8>(teams[p]) += gols_b;
                    auto q = find(teams, time_b, t);
                    get<1>(teams[q]) += 3;
                    get<2>(teams[q])++;
                    get<3>(teams[q])++;
                    get<6>(teams[q]) += gols_b - gols_a;
                    get<7>(teams[q]) += gols_b;
                    get<8>(teams[q]) += gols_a;
                }
        }
        sort(teams.begin() + 1, teams.end(), compare);
        if(++m > 1)
            printf("\n");
        cout << a << "\n";
        int cont;
        for(cont = 1; cont <= t; cont++)
            cout << cont << ") " << get<0>(teams[cont]) << " " << get<1>(teams[cont]) << "p, " << get<2>(teams[cont]) << "g ("
            <<   get<3>(teams[cont]) << "-" << get<4>(teams[cont]) << "-"
            << get<5>(teams[cont]) << "), " << get<6>(teams[cont]) << "gd (" << get<7>(teams[cont]) << "-" << get<8>(teams[cont]) << ")\n"; 
    }
    return 0;
}