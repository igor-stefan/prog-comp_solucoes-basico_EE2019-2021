#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 3;

int main(){
    int n, temp;
    vector<int> ans1, ans2, ans3;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &temp);
        if(temp < 0) 
           ans1.push_back(temp);
        else if (temp > 0)
            ans2.push_back(temp);
        else 
            ans3.push_back(temp);
    }
    if(ans2.size() == 0){
        while(ans2.size() < 2){
            ans2.push_back(ans1.back());
            ans1.pop_back();
        }
    }
    if(ans1.size() % 2 == 0){
        ans3.push_back(ans1.back());
        ans1.pop_back();
    }

    printf("%d ", (int)ans1.size());
    for(int i = 0; i< ans1.size(); i++)
        printf("%d ", ans1[i]);
    printf("\n");
        printf("%d ", (int)ans2.size());
    for(int i = 0; i< ans2.size(); i++)
        printf("%d ", ans2[i]);
    printf("\n");
        printf("%d ", (int)ans3.size());
    for(int i = 0; i < ans3.size(); i++)
        printf("%d ", ans3[i]);
    printf("\n");
    return 0;
}