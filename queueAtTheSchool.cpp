#include <bits/stdc++.h>

using namespace std;

void swapPositions(string& a, int t){
    while(t--){
        bool moved[a.size()];
        for(int i = 0; i < a.size(); i++)
            moved[i] = false;
        for(int i = 0; i < a.size() - 1; i++)
            if(a[i] == 'B' and a[i + 1] == 'G' and !moved[i]){
                char temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                moved[i] = moved[i + 1] = true;
            }
    }
}

int main(){
    int n, t;
    string queue;
    scanf("%d %d", &n, &t);
    cin >>  queue;
    swapPositions(queue, t);
    cout << queue << "\n";
    return 0;
}