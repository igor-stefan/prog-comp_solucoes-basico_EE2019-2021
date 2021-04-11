#include <bits/stdc++.h>

using namespace std;

int numberOfDigits(int n){
    int cont = 0;
    while(n >= 10 ){
        n /= 10;
        cont++;
    }
    return cont + 1;
}


int main(){
    string num;
    while(cin >> num){
        if(num == "END")
            break;
        int n = num.size(), a = -1;
        if(n < 2)
            a = stoi(num);
        int next, last = n, i = 1;
        if(a == n)
            printf("%d\n", i);
        else{
            while(true){
                next = numberOfDigits(last);
                i++;
                if(next == last)
                    break;
                last = next;
            }
            printf("%d\n", i);
        }
    }

    return 0;
}