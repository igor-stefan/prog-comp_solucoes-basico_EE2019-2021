#include <bits/stdc++.h>
#define TAM 55
#define f(a,b) for(int i=int(a); i<int(b); i++)
#define ff(a,b) for(int j=int(a); j<int(b); j++)
using namespace std;

int n, m;
char mat[TAM][TAM];

bool find(pair<int,int> loc, string s){
    int x=loc.first, y=loc.second;
    f(0,n){
        ff(0,m){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    int i=0;
    while(x<n and mat[x][y]==s[i] and i<s.size()){
        x++; i++;
    }
    if(i==s.size())return true;
    x=loc.first; y=loc.second;
    i=0;
    while(x>=0 and mat[x][y]==s[i] and i<s.size()){
        x--; i++;
    }
    if(i==s.size())return true;
    x=loc.first; y=loc.second;
    i=0;
    while(y<m and mat[x][y]==s[i] and i<s.size()){
        y++; i++;
    }
    if(i==s.size())return true;
    x=loc.first; y=loc.second;
    i=0;
    while(y>=0 and mat[x][y]==s[i] and i<s.size()){
        y--; i++;
    }
    if(i==s.size())return true;
    x=loc.first; y=loc.second;
    i=0;
    while(x<n and y<m and mat[x][y]==s[i] and i<s.size()){
        x++; y++; i++;
    }
    if(i==s.size())return true;
    x=loc.first; y=loc.second;
    i=0;
    while(x>=0 and y>=0 and mat[x][y]==s[i] and i<s.size()){
        x--; y--; i++;
    }
    if(i==s.size())return true;
    x=loc.first; y=loc.second;
    i=0;
    while(x>=0 and y<m and mat[x][y]==s[i] and i<s.size()){
        x--; y++; i++;
    }
    if(i==s.size())return true;
    x=loc.first; y=loc.second;
    i=0;
    while(x<n and y>=0 and mat[x][y]==s[i] and i<s.size()){
        x++; y--; i++;
    }
    if(i==s.size())return true;
    return false;
}

void func(string s, vector<set<pair<int,int> > > &posis){
    int letra = tolower(s[0])-'a';
    auto it = posis[letra].begin();
    cout<<"tam: "<<posis[letra].size()<<endl;

    while(it!=posis[letra].end()){
        if(find(*it,s)){
            //cout<<it->first<<"..........."<<it->second<<'\n';
            return;
        }
        it++;
    }cout<<"-1\n";
}

int main(){
    int t, c;
    cin>>t;
    string s;
    while(t--){
        cin>>n>>m;
        vector<set<pair<int,int> > > posi(30);
        char mat[n][m];
        f(0,n){
            ff(0,m){
                cin>>mat[i][j];
                mat[i][j]=tolower(mat[i][j]);
                //cout<<mat[i][j]<<"-";
                int letra = mat[i][j] - 'a';
                posi[letra].insert(make_pair(i,j));
                //cout<<mat[i][j]<<" "<<letra<<" "<<posi[letra].size()<<endl;;
            }
            cout<<endl;
        }
        cin>>c;
        /*
        f(0,n){
            ff(0,m){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        f(0,c){
            cin>>s;
            string aux;
            for(auto k:s)aux+=tolower(k);
            cout<<"......"<<aux<<endl;
            func(aux, posi);
        }
    }
}