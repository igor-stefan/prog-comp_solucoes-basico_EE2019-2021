#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 3;

vector<int> firstGreaterElement(int a[], int n){
    vector<int> ans(n + 1, 0);
    stack<int> st;
    for(int i = 1; i <= n; i++){
        while(!st.empty() and a[i] > a[st.top()]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main(){
    int n, a[Nmax];
    if(scanf("%d", &n) != 1){
        printf("Invalid inputs\n");
        exit(EXIT_FAILURE);
    };
    for(int i = 1; i <= n; i++)
        if(scanf("%d", &a[i]) != 1){
            printf("Invalid inputs\n");
            exit(EXIT_FAILURE);
        } 
    vector<int> ans = firstGreaterElement(a, n);
    for(auto x = ans.begin() + 1; x != ans.end(); x++ )
        printf("%d ", *x);
    printf("\n");
}