#include <bits/stdc++.h>

using namespace std;

int k=0,n=0,temp=0,how_many_advance=0;
bool advice=false;
int main(){
vector<int> points;
    cin>>n>>k;
    int tam=n;
    while(tam--){
        cin>>temp;
        points.push_back(temp);
    }

    for(int i = 0;i<k;i++){
        if(points[i]>0)how_many_advance++;
        else {
            advice=true;
            break;
        }
    }
    if(!advice){
        for(int j=k-1;j<n-1;j++){
            if(points[j+1]>=points[j])how_many_advance++;
            else break;
        }
    }
    cout<<how_many_advance<<endl;
        
    return 0;
}