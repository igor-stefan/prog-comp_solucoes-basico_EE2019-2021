#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 3;
int freq[7 + 1];

int main(){
    int n, a[Nmax];
    vector<int> ans;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }
    // for(int i = 1; i <= 7; i++)
    //     printf("%d ",freq[i]);
    // printf("\n");
    for(int i = 1; i <= 7; i++){
        while(freq[i]-- != 0){
            int cont = 1, j = i, current_number = j;
            ans.push_back(j);
            while(cont < 3){
                while(!(j > current_number and j % current_number == 0 and freq[j] != 0) and j <= 7)
                    j++;
                if(j <= 7){
                    current_number = j;
                    ans.push_back(j);
                    cont++;
                    freq[j]--;
                }
                else{
                    printf("-1\n");
                    return 0;
                }
        }
    }
}
    for(int i = 0; i < ans.size(); i += 3)
        for(int j = 0; j <= 2; j++)
            if(j <= 1)
                printf("%d ",ans[i + j]);
            else
                printf("%d\n",ans[i + j]); 
    return 0;
}