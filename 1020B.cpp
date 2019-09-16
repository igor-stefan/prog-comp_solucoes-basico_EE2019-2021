#include <bits/stdc++.h>
#define fo(i,p) for(int i=0;i<p;i++)
using namespace std;

int alunos[1005];
bool visited[1005];

int dfs (int a){
    memset(visited,0,sizeof(visited));
    int vez=a;
    while(visited[vez]==0){
        visited[vez]=1;
        vez=alunos[vez];
    }
    return vez;
}
int main(){
int temp,n=0;
scanf("%i",&n);
fo(i,n){
    scanf("%i",&alunos[i]);
    alunos[i]--;
}
fo(i,n){
    cout<<dfs(i)+1<<" ";
}
    cout<<"\n";
    return 0;
}