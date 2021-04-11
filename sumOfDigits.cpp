#include <bits/stdc++.h>

using namespace std;


int sumOfDigits(string a, int len){
    if(len == 1)
        return 0;
    long long sum = 0;
    for(int i = 0; i < len; i++)
        sum += a[i] - '0';
    a = to_string(sum);
    return 1 + sumOfDigits(a, a.size());
}


int main() {
    string a;
    cin >> a;
    printf("%d\n", sumOfDigits(a, a.size()));
    return 0;
}