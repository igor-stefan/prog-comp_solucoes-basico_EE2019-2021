#include <bits/stdc++.h>

using namespace std;

int main (){
    int n, temp, numOfTwoHundred = 0, numOfOneHundred = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &temp);
        if(temp == 200)
            numOfTwoHundred++;
        else
            numOfOneHundred++; 
    }
    int sum = numOfTwoHundred * 200 + numOfOneHundred * 100;
    if((sum / 100) % 2 != 0){
        printf("NO\n");
        return 0;
    }
    else{
        int half = sum / 2;
        bool flag = false;
        for(int i = 0; i <= numOfTwoHundred; ++i)
            if(200 * i <= half and half - 200 * i <= numOfOneHundred * 100)
                flag = true;
        flag? printf("YES\n") : printf("NO\n");
    }

}