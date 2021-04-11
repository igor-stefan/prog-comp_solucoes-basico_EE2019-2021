#include <bits/stdc++.h>
#define f(a, b) for (int i = a; i < b; i++)
#define ff(a, b) for (int j = a; j < b; j++)
#define pb push_back
#define mp make_pair
#define TAM 55
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi >
#define vvvi vector<vvi >
using namespace std;

int main(){
    map<int,int> DH, DM;
    DH[0]=0; DH[12]=0;
    DH[1]=30; DH[13]=30;
    DH[2]=60; DH[14]=60;
    DH[3]=90; DH[15]=90;
    DH[4]=120; DH[16]=120;
    DH[5]=150; DH[17]=150;
    DH[6]=180; DH[18]=180;
    DH[7]=210; DH[19]=210;
    DH[8]=240; DH[20]=240;
    DH[9]=270; DH[21]=270;
    DH[10]=300; DH[22]=300;
    DH[11]=330; DH[23]=330;
    f(0,61){
        DM[i]= i * 6;
    }
    double deg_h, deg_m, ph, pm;
    char c;
    while(cin>>ph>>c>>pm and (ph or pm)){
        //cout<<ph<<c<<pm<<endl;
        deg_h=DH[ph];
        deg_m=DM[pm];
        deg_h += pm * 0.5;
        double dif=(deg_h-deg_m);
        if(dif > 180.0)
            dif = abs(360.0 - dif);
        if(dif < 0)
            dif *= -1;
        cout<<fixed<<setprecision(3)<<dif<<'\n';
    }
}