/*Given an array of integers of size ‘n’.
Our aim is to calculate the maximum sum of ‘k’ 
consecutive elements in the array.
Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4 
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23}
of size 4.
*/

#include <bits/stdc++.h>

using namespace std;
const int sizeMax = 1e2 + 2;

int slideWindow(int a[], int n, int k){
    int cur_sum = 0;
    for(int i = 0; i < k; i++)
        cur_sum += a[i];

    for(int i = k; i < n; i++)
        cur_sum = max(cur_sum, cur_sum + a[i] - a[i - k]);
    
    return cur_sum;
}

int slideWindow2(int a[], int n, int k, int& start, int& end){
    int nElements = 0, ans = 0, Right;
    unordered_map<int, int> freq;
    for(Right = 0; Right < n; Right++){
        if(freq[a[Right]]++ == 0)
            nElements++;
        if(nElements > k)
            break;
    }
    if(nElements <= k)
        return n;
    if(--freq[a[Right--]] == 0)
        nElements--;
    
    for(int Left = 1; Left < n; Left++){
        if(--freq[a[Left - 1]] == 0)
            nElements--;
        while(Right < n){
            if(freq[a[++Right]]++ == 0)
                nElements++;
            if(nElements > k)
                break;
        }
        if(nElements <= k)
            return max(ans, n - Left + 1);
        if(--freq[a[Right--]] == 0)
            nElements--;
        if(Right - Left + 1 > ans){
            ans = Right - Left + 1;
            start = Left;
            end = Right;
        }
    }
    return ans;
}

int main(){
    int a[sizeMax], n, k, start, end;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    printf("%d ", slideWindow2(a, n, k, start, end)); 
    printf("[%d, %d]\n", start, end);
    return 0;
}