#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 * 2 + 5;
int dp[Nmax], pred[Nmax];


void reconstructDp(int i, int pred[]){
    vector<int> path = {i};
    int actual_index = i;
    while(pred[actual_index] != -1){
        actual_index = pred[actual_index];
        path.push_back(actual_index);
    }
    reverse(path.begin(), path.end());
    for(auto& x: path)
        cout << x << " ";
    cout << "\n";
}

void dP(int a[], int n){
    map<int, int> maxValue;
    int ans = 1, index = 1;
    pred[0] = -1;
    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        pred[i] = -1;
        if(maxValue.find(a[i] - 1) != maxValue.end()){
            int j = maxValue[a[i] - 1];
            pred[i] = j;
            dp[i] += dp[j];
            if(ans < dp[i]){
                ans = dp[i];
                index = i;
            }
        }
        maxValue[a[i]] = i;
    }
    cout << ans << "\n";
    reconstructDp(index, pred);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a[Nmax];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dP(a,n);
    return 0;
}