#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005]; //adjacencia
int custo [100005]; //custo de cada pessoa
bool visited[100005]; //vetor de visita
int N,M,custo_min=0; //variaveis
long long ans=0; //resposta

void dfs(int no){
	if(!visited[no]){ //se o no nao foi visitado
		visited[no]=true; //marco como visitado
		custo_min = min(custo_min,custo[no]); //pego o custo minimo do no
		for(int i : adj[no]){ dfs(i);} //faço a dfs nos adjacentes do no
	}
}

int main(){
	scanf("%i %i", &N,&M);
	for(int i=0;i<N;i++){
		cin>>custo[i];
	}
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		//criei a lista de adjacencia
	}
for(int j=0;j<N;j++){
	if(!visited[j]){ //se eu nao visitei o no
		custo_min=custo[j];//o custo minimo dos componentes inicia com o custo do primeiro no
		dfs(j); //faco a dfs nesse no
		ans+=custo_min;

	}
}
cout<<ans<<"\n";
	return 0;
}