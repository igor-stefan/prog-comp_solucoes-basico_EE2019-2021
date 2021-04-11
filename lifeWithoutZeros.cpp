#include <bits/stdc++.h>

using namespace std;

void removeZeros(string& a){
    string ans = "";
    for(int i = 0; i < a.size(); i++)
        if(a[i] != '0')
            ans += a[i];
    a = ans;
}


int main(){
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = a + b;
    string a1 = to_string(a), b1 = to_string(b), c1 = to_string(c);
    removeZeros(a1);
    removeZeros(b1);
    removeZeros(c1);
    a = stoi(a1);
    b = stoi(b1);
    c = stoi(c1);
    if(c == a + b)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}