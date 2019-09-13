#include <bits/stdc++.h>
#define fo(i,k,n) for(int i=k;i<=n;i++)
#define fa(i,n) for(int i=0;i<n;i++)
using namespace std;

map<string,int> dupla;
string palavras[100005];
int custo[100005],custo_grupo[100005];
long long res=0;
int n,m,k;
int main(){
cin>>n>>k>>m; //recebo as entradas
fo(i,1,n){ //armazeno as palavras
    string a;
    cin>>a;
    palavras[i]=a;
}
fo(i,1,n){ //armazeno o custo de cada palavra, os indices da palavra e de seu custo sao iguais
    cin>>custo[i];
    custo_grupo[i]=(1<<30); //inicio cada indice do custo do grupo com o valor de 2³⁰
}
fo(i,1,k){//organizo os grupos
    int x; 
    cin>>x; //recebo o num de elementos de um grupo 
    while(x--){
        int idx; //recebo o indice correspondente a uma palavra
        cin>>idx;
        custo_grupo[i]=min(custo_grupo[i],custo[idx]); //intero o custo de cada palavra
        dupla[palavras[idx]]=i; //asssim consigo pegar o menor custo do grupo
        //adiciono as palavras de um mesmo grupo no map com os indices do grupo
    }
}
while(m--){
    string y;
    cin>>y; //recebo a mensagem que foi enviada
    res+=custo_grupo[dupla[y]]; //calculo o custo total somando o custo do grupo em que cada
    //palavra está. o indice do grupo é o mesmo indice da palavra que esta no map
}
cout<<res<<endl;
    return 0;
}