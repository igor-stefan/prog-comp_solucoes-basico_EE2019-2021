#include <bits/stdc++.h>

using namespace std;

const int lim = 1e9 + 1;

vector<long long> lucky_Numbers;
void generateLuckyNumbers(long long num){
    lucky_Numbers.push_back(num);
    if(num < lim){
        generateLuckyNumbers(10 * num + 4);
        generateLuckyNumbers(10 * num + 7);
    }
}

void findNext(int num, int n, long long& next, int& index){
    int left = index, right = n;
    while(left <= right){
        int mid = (left + right)/ 2;
        if(1LL * num <= lucky_Numbers[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    next = lucky_Numbers[left];
    index = left;
}

int main(){
    generateLuckyNumbers(0);
    sort(lucky_Numbers.begin(), lucky_Numbers.end());
    int l, r, index = 0;
    long long sum = 0, next = 0;
    scanf("%d %d", &l, &r);
    for(int i = l; i <= r; i++){
        if(i <= next)
            sum += next;
        else{
            findNext(i, lucky_Numbers.size() - 1, next, index);
            sum += next;
        }
    }
    printf("%lld\n", sum);
    return 0;
}