#include <bits/stdc++.h>

using namespace std;

const int Nmax = 10;

int find(vector<tuple<string, int, int>>& vt, string a, int cont){
    int index;
    for(int i = 0; i < cont; i++){
        if(get<0>(vt[i]) == a){
            index = i;
            break;
        }
    }
    return index;
}

int main(){
    int n, z = 0;
    while(scanf("%d", &n) == 1){
        if(++z != 1)
            printf("\n");
        vector<tuple<string, int, int>> group(Nmax);
        int cont = 0;
        string name;
        for(cont = 0; cont < n; cont++){
            cin >> name;
            group[cont] = make_tuple(name, 0, 0);
        }
        for(int i = 1; i <= cont; i++){
            string x;
            int money, friends, t, k = 0, p = 0;
            cin >> x >> money >> friends;
            if(friends > 0){
                p = money % friends;
                k = money / friends;
                t = find(group, x, cont);
                // cout << "p = " << p << " k = " << k << '\n';
                // get<1>(group[t]) += p;
                get<2>(group[t]) += money - p;
                // cout << "ganho = " << get<1>(group[t]) << " deve = " << get<2>(group[t]) << " t = " << t << "\n";
            }
            for(int j = 1; j <= friends; j++){
                string now;
                cin >> now;
                t = find(group, now, cont);
                get<1>(group[t]) += k;
            }
        }
        for(int i = 0; i < cont; i++)
            cout << get<0>(group[i]) << " " << get<1>(group[i]) - get<2>(group[i]) << "\n";
    }
    return 0;
}