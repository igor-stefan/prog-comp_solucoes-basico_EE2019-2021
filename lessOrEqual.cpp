#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2 * 1e5 + 3;

int main() {
    int n, k, a[Nmax];
    stack<int> st;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    if(k == 0){
        if(a[1] - 1 >= 1)
            cout << a[1] - 1 << "\n";
        else
            cout << -1 << "\n";
        return 0;
    }
    int i;
    for(i = 1; i <= k; i++)
        st.push(a[i]);
    if(i <= n){
        if(a[i] == st.top())
            cout << -1 << "\n";
        else cout << st.top() << "\n";
    }else
        cout << st.top() << "\n";

    return 0;
}