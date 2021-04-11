#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 200;
 
int w , h , Max , step , flag , sum;
//Max finds the maximum number of steps in the step. step is used to calculate the number of steps in each search. flag determines whether there is an out of bound. sum stores the maximum number of rings.
 Int num[MAXN][MAXN];//Store the converted values ​​of '\' and '/' in this array
 Int vis[MAXN][MAXN];//The mark has passed
 Int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{ 0,-1},{-1,-1}};//direction array
 
 //Deep search
void dfs(int i , int j){
    int k;
    for(k = 0 ; k < 8 ;k++){
        if(i+dir[k][0] < 0 || i+dir[k][0] >= 2*h){
                           Flag = 0 ; continue; / / If the out of bounds, mark flag as 0
        }
        if(j+dir[k][1] <0 || j+dir[k][1] >= 2*w){
                           Flag = 0; continue;//If the out of bounds, mark flag as 0
        }
                 If(num[i+dir[k][0]][j+dir[k][1]] != 0)//If there is a value, it cannot be taken
             continue;
                 If(vis[i+dir[k][0]][j+dir[k][1]] != 0)//If you pass or the origin, you can’t go
             continue;
                 If(num[i+dir[k][0]][j+dir[k][1]] == 0 && vis[i+dir[k][0]][j+dir[k][1 ]] == 0 ){//The satisfaction value is 0 and no further search continues (remember that I clocked the search direction by the number 0~7)
                if(k == 1){
                    if(num[i-1][j] == 1 && num[i][j+1] == 1){
                        vis[i-1][j+1] = 1;
                                                 Step++; / / corresponding to add a step
                        dfs(i-1 , j+1);
                    }
                }
                else if(k == 5){
                    if(num[i+1][j]== 1 && num[i][j-1] == 1){
                        vis[i+1][j-1] = 1;
                                                 Step++;;// corresponding to add a step
                        dfs(i+1 , j-1);
                    }
                }
                else if(k == 3){
                    if(num[i][j+1] == -1 && num[i+1][j] == -1){
                        vis[i+1][j+1] = 1;
                                                 Step++;;// corresponding to add a step
                        dfs(i+1 , j+1);
                    }
                }
                else if(k == 7){
                    if(num[i-1][j] == -1 && num[i][j-1] == -1){
                        vis[i-1][j-1] = 1;
                                                 Step++;;// corresponding to add a step
                        dfs(i-1 , j-1);
                    }
                }
                else{
                    vis[i+dir[k][0]][j+dir[k][1]] = 1;
                                         Step++;;// corresponding to add a step
                    dfs(i+dir[k][0] , j+dir[k][1]);
                }
            }
       
    }
}
 
 / / Handle the problem function
void solve(){
    int i , j;
         Memset(vis , 0 , sizeof(vis));//initialization
    Max = 0;sum = 0;
    for(i = 0 ; i < 2*h ; i++){
       for(j = 0 ; j < 2*w ; j++){
           if(num[i][j] == 0 && vis[i][j] == 0){
                               Step = 1;flag = 1; / / initialized to 1
                               Vis[i][j] = -1;//The first price is -1
                               Dfs(i , j);//search
               Vis[i][j] = 1;// is marked as 1 in the new
                               If(flag){//If it is a ring, then add plus, determine the maximum Max
                   sum++;
                  if(Max < step)
                     Max = step;
               }
           }
       }   
    }
}
 
 / / Main function
int main(){
    int i , j , t = 1;
    char ch;
         While(scanf("%d%d%*c" , &w , &h) &&w &&h){ //Read in judgment
        memset(num , 0 , sizeof(num));
        for(i = 0 ; i < h ;i++){
            for(j = 0 ; j < w ; j++){
                scanf("%c" , &ch);
                                 If(ch == '\\'){//If ‘\’ is turned into -1
                   num[2*i][j*2] = -1;
                   num[2*i+1][j*2+1] = -1;
                }
                                 If(ch == '/'){//If it is '/', it is 1
                   num[2*i+1][2*j] = 1;
                   num[2*i][2*j+1] = 1;        
                }
            }
            getchar();
        }
        solve();
        printf("Maze #%d:\n" ,t);
        if(sum).
            printf("%d Cycles; the longest has length %d.\n\n" ,sum ,Max);
        else
            printf("There are no cycles.\n\n");
        t++;
    }
    return 0;
}
 