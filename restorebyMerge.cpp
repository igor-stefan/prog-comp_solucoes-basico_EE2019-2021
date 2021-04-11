#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100 + 3;


void restorePermutation(int a[], int n){
    vector<int> solution;
    vector<bool> fr(n + 1, false);
    for(int i = 1; i <= n; i++){
        if(!fr[a[i]]){
            fr[a[i]] = true;
            solution.push_back(a[i]);
        }
    }
    for(auto& x: solution)
        printf("%d ", x);
    printf("\n");
}

int main() {
    int t, n, a[Nmax];
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d", &n);
        for(int j = 1; j <= 2 * n; j++)
            scanf("%d", &a[j]);
        restorePermutation(a, 2 * n);
    }

    return 0;
}