#include <bits/stdc++.h>

using namespace std;

const int Mmax = 20 + 1;

int main(){
    int n, s;
    while(cin >> n >> s){
        if(n == 0)
            break;
        int points[Mmax];
        for(int i = 1; i <= 2 * n; i++)
            scanf("%d", &points[i]);
        int sum = 0, j = 1;
        while(sum < s){
            cout << "sum = " << sum << " j = " << j << "\n";
            sum += points[j++];
            cout << "sum = " << sum << " j = " << j << "\n";
            if(j > 2 * n)
                j = 1;
            if(sum >= s)
                break;
        }
        if(j % 2)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}