#include <bits/stdc++.h>

using namespace std;

bool isGood(vector<int>& v, int init){
        deque<int> dq(v.begin() + init, v.end());
        int ant = INT_MIN;
        while(!dq.empty() && (ant <= min(dq.back(), dq.front()))){
            if(dq.back() <= dq.front()){
                ant = dq.back();
                // cout << "popei " << ant << endl;
                dq.pop_back();
            }
            else{
                ant = dq.front();
                // cout << "popei " << ant << endl;
                dq.pop_front();
            }
        }
        // cout << " empty ? " << dq.empty() << endl;
        return dq.empty();
}

int bs(vector<int>& v){
    int n = v.size();
    int left = 0, right = n - 1, mid;
    if(n == 1) return 0;
    int cont = 0;
    while(left <= right){
        // cout << ++cont << endl;
        mid = (left + right) / 2;
        // cout << "left = " << left << " right = " << right << " mid = " << mid << endl;
        if(isGood(v, mid))
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return left;
}

int main(){
    int t, n, temp;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        vector<int> v;
        scanf("%d", &n);
        for(int j = 1; j <= n; j++){
            cin >> temp;
            v.push_back(temp);
        }
        printf("%d\n",bs(v));
    }
    return 0;
}