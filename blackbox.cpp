#include <bits/stdc++.h>

using namespace std;

const int Nmax = 3 * 1e4 + 5;

int main(){
    int k;
    scanf("%d", &k);
    for(int j = 1; j <= k; j++){
        if(j > 1)
            printf("\n");
        vector<int> numbers(Nmax), gets(Nmax);
        priority_queue<int> a;
        priority_queue<int, vector<int>, greater<int>> b; //ordenado do menor para o maior
        string ax;
        getline(cin, ax);
        int add, get;
        scanf("%d %d", &add, &get);
        for(int i = 1; i <= add; i++)
            scanf("%d", &numbers[i]);
        for(int i = 1; i <= get; i++){
            int temp;
            scanf("%d", &temp), gets[temp]++;
        }
        for(int i = 1; i <= add; i++){
            a.push(numbers[i]);
            b.push(a.top());
            a.pop();
            while(gets[i]--){
                printf("%d\n", b.top());
                a.push(b.top());
                b.pop();
            }            
        }
    }
    return 0;
}