#include <bits/stdc++.h>

using namespace std;


double numOfClones(int n, int x, int y){
    return ceil((double) y * n / 100);
}

int main(){
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    double people_in_demonstration = numOfClones(n, x, y) - x;
    if(people_in_demonstration < 0)
        people_in_demonstration = 0;
    printf("%g\n", people_in_demonstration);
    return 0;
}