#include <bits/stdc++.h>

using namespace std;

int main(){
    int c;
    scanf("%d", &c);
    while(c--){
        printf("c = %d\n", c);
        int n, t, m, a, tempo = 0;
        string lado;
        queue<int> left, right;
        scanf("%d %d %d", &n, &t, &m);
        for(int i = 1; i <= m; i++){
            cin >> a >> lado;
            if(lado == "left")
                left.push(a);
            else
                right.push(a);
        }
        bool lleft = true;
        while(!left.empty() or !right.empty()){
            printf("t =  %d lleft = %d\n", tempo, lleft);
            int k = 0;
            if(left.front() > tempo or right.front() > tempo)
                tempo += t;
            else{
                cout << "aqui\n";
                if(left.front() <= tempo){
                    if(!lleft){
                        tempo += t;
                        lleft = !lleft;
                    }
                }else{
                    if(lleft){
                        tempo += t;
                        lleft = !lleft;
                    }
                }
                if(lleft){
                    while(!left.empty() and k < n){
                        if(left.front() <= tempo){
                            printf("%d\n", tempo + t);
                            left.pop();
                            k++;
                        }
                        else
                            break;
                    }
                }else{
                    while(!right.empty() and k < n){
                        if(right.front() <= tempo){
                            printf("%d\n", tempo + t);
                            right.pop();
                            k++;
                        }
                        else
                            break;
                    }
                }
            }
        }
    }
    return 0;
}