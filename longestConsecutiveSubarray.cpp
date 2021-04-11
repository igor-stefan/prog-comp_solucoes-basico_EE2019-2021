#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 2;

void reset(bool a[], int n){
    for(int i = 1; i <= n; i++)
        a[i] = false;
}

int LCS(int a[], int n, int& start, int& end){
    bool freq[n];
    int Min, Max, ans = 1;
    for(int left = 1; left <= n; left++){
        Max = Min = a[left];
        reset(freq, n);
        for(int right = left; right <= n; right++ ){
            if(freq[a[right]]) break;
            Min = min(Min, a[right]);
            Max = max(Max, a[right]);
            freq[a[right]] = true;
            if(Max - Min + 1 == right - left + 1 && right - left + 1 > ans){
                start = left;
                end = right;
                ans = right - left + 1;
            }
        }
    }
    return ans;
}

int main(){
    int n, a[Nmax], start, end;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("%d ", LCS(a, n, start, end));
    printf("[%d, %d]\n", start, end);
    return 0;
}