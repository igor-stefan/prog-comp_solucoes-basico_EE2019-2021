#include <bits/stdc++.h>

using namespace std;

void resolve(map<string, string>& names, map<string, pair<string, string>>& rel, string t1, string t2, string t3){
    // cout << "t1 = " << t1 << "\n";
    auto p = names.find(t2);
    auto l = names.find(t3);
    if(p == names.end())
        resolve(names, rel, t2, rel[t2].first, rel[t2].second);
    if(l == names.end())
        resolve(names, rel, t3, rel[t3].first, rel[t3].second); 
    auto x = names[t2];
    auto y = names[t3];
    // cout << "x = " << x << " y = " << y << "\n";
    if(x == "dominant" or y == "dominant"){
            if((x == "dominant" and y == "dominant") or
                (x == "dominant" and y == "recessive") or
                (x == "recessive" and y == "dominant") )
                    names[t1] = "dominant";
            else
                    names[t1] = "recessive";
            }
        else if(x == "recessive" and y == "recessive")
            names[t1] = "recessive";
        else
            names[t1] = "non-existent";
    // cout << "coloquei " << t1 << " como " << names[t1] << "\n";
}

int main(){
    int k;
    while(scanf("%d", &k) == 1){
        map<string, string> names;
        map<string, pair<string, string>> rel;
        for(int i = 1; i <= k; i++){
            string a, b;
            cin >> a >> b;
            if(b == "non-existent" or b == "recessive" or b == "dominant")
                names[a] = b;
            else{
                if(rel[b].second == "x"){
                    rel[b].second = a;
                }
                else
                    rel[b] = {a, "x"};
            }
        }  
        // for(auto it = rel.begin(); it != rel.end(); it++){
        //     cout << it->first << " -> " << it -> second.first << " e " << it -> second.second << "\n";
        // }
        int cont = names.size();
        int n = rel.size(); 
        for(auto it = rel.begin(); it != rel.end(); it++){
            resolve(names, rel, it->first, it->second.first, it->second.second);
            if((int)names.size() == n + cont)
                break;
        }
        for(auto it = names.begin(); it != names.end(); it++)
            cout << it -> first << " " << it -> second << "\n";
    }
    return 0;
}