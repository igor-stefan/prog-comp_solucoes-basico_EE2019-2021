#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, maxNumOfPassengers = INT_MIN, numOfPassengers = 0, a, b;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &a, &b);
        numOfPassengers -= a;
        numOfPassengers += b;
        maxNumOfPassengers = max(maxNumOfPassengers, numOfPassengers);
    }
    printf("%d\n", maxNumOfPassengers);
    return 0;
}