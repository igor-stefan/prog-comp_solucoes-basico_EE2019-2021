#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;
long long sum[Nmax], sum_ordened[Nmax];

void buildSum(int a[], int n){
    sum[1] = a[1];
    for(int i = 2; i<= n; i++)
        sum[i] = sum[i - 1] + a[i];
}

void buildSum0rdened(int a[], int n){
    sum_ordened[1] = a[1];
    for(int i = 2; i<= n; i++)
        sum_ordened[i] = sum_ordened[i - 1] + a[i];
}

long long solveQueryOne(int left, int right){
    return sum[right] - sum[left - 1];
}

long long solveQueryTwo(int left, int right){
    return sum_ordened[right] - sum_ordened[left - 1];
}

int main() {
    int n, questions, type, left, right, val[Nmax];
    scanf("%d", &n);
    for(int i = 1; i<= n; i++)
        scanf("%d", &val[i]);
    buildSum(val, n);
    sort(val + 1, val + n + 1);
    buildSum0rdened(val, n);
    scanf("%d", &questions);
    while(questions--){
        scanf("%d %d %d", &type, &left, &right);
        if(type == 1)
            printf("%lld\n", solveQueryOne(left, right));
        else
            printf("%lld\n",solveQueryTwo(left, right));
    }
    return 0;
}