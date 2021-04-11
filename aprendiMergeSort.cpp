#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 3;

void mergeArrays(int a[], int n, int left, int mid, int right){
    int i = left, j = mid + 1, p = 1, b[n];
    while(i <= mid and j <= right){
        if(a[i] > a[j])
            b[p++] = a[i++];
        else
            b[p++] = a[j++];;
    }
    while(i <= mid)
        b[p++] = a[i++];
    while(j <= right)
        b[p++] = a[j++];
    for(i = left; i <= right; i++)
        a[i] = b[i - left + 1];
}

void mergeSort(int a[], int n, int left, int right){ 
    if(left == right)
        return;
    int mid = (left + right) / 2;
    mergeSort(a, n, left, mid);
    mergeSort(a, n, mid + 1, right);
    mergeArrays(a, n, left, mid, right);
}

int main(){
    int n, a[Nmax];;
    scanf("%d", &n);
    for(int i = 1; i <=n ; i++)
        scanf("%d",&a[i]);
    int left = 1, right = n;
    mergeSort(a, n, left, right);
    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
}