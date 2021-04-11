#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e4 + 3;

int greedy(int a[], int n, int& start, int& end){ //O(n)
    int maxS = a[1], sum = 0;
    start = 1; end = n;
    for(int i = 1; i <= n; i++){
        sum += a[i];
        if(sum > maxS){
            maxS = sum;
            end = i;
        }
        if(sum < 0){
            sum = 0;
            start = i;
        }
    }
    return maxS;
}

int partialSum(int a[], int n, int& start, int& end){ //O(n)
    vector<int> ps(n + 1, 0);
    int minS = a[1], ans = a[1];
    ps[1] = a[1]; 
    start = 1; end = n;
    for(int i = 2; i <= n; i++)
        ps[i] = ps[i - 1] + a[i];
    for(int i = 1; i <= n ; i++){
        if(ps[i] - minS > ans){
            ans = ps[i] - minS;
            end = i;
        }
        if(ps[i] < minS){
            minS = ps[i];
            start = i;
        }
    }
    return ans;
}

int maxSumLeft(int a[], int left, int mid){
    int ans = a[mid], sum = 0;
    for(int leftPointer = mid; leftPointer >= left; leftPointer--){
        sum += a[leftPointer];
        ans = max(ans, sum);
    }
    return ans;
}

int maxSumRight(int a[], int right, int mid){
    int ans = a[mid + 1], sum = 0;
    for(int rightPointer = mid + 1; rightPointer <= right; rightPointer++){
        sum += a[rightPointer];
        ans = max(ans, sum);
    }
    return ans;
}

int maxSumSubarray(int a[], int left, int right){ //O(n log n)
    if(left == right)
        return a[left];
    int mid = (left + right) / 2;
    int ans = max(
        maxSumSubarray(a, left, mid),
        maxSumSubarray(a, mid + 1, right)
        );
    return max(ans, maxSumLeft(a, left, mid) + maxSumRight(a, right, mid));
}

int main() {
    //index 1
    int n , a[Nmax], start, end;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("greedy = %d ", greedy(a, n, start, end));
    printf("[%d, %d]\n", start, end);
    printf("partial sum = %d ", partialSum(a, n, start, end));
    printf("[%d, %d]\n", start, end);
    printf("divide and conquer = %d\n", maxSumSubarray(a, 1, n));
    return 0;
}