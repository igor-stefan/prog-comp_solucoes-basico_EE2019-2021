#include <bits/stdc++.h>

using namespace std;

const int points = 10;

int main(){
    int n;
    scanf("%d", &n);
    if(n <= 10) 
        printf("0\n");
    else if(n - points > 11)
        printf("0\n");
    else if(n - points == 10)
        printf("15\n");
    else if(n - points == 11)
        printf("4\n");
    else
        printf("4\n");
    return 0;
}