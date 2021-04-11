#include <bits/stdc++.h>

using namespace std;


const int m = 5842;

int nums[] = {2, 3, 5, 7};
vector<int> ans(nums, nums + 4);

void gerar_numeros(){
    int cont = 0;
    bool flag = false;
    for(int i = 0; i < 4; i++){
        int k = ans.size();
        for(int j = 0; j < k; j++){
            ans.push_back(ans[j] * nums[i]);
            cont++;
        if(cont == m){
            flag = true;
            break;
        }
        }
        if(flag)
            break;
    }
}


int main(){
    int n;
    gerar_numeros();
    for(int i = 0; i < m; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    // while(scanf("%d", &n) == 1){
    //     if(n == 0)
    //         break;
    // printf("%d\n", &nums[n]);        
    // }

    return 0;
}