#include <bits/stdc++.h>

using namespace std;

int main(){
    int c;
    scanf("%d", &c);
    while(c--){
        string a;
        getline(cin, a);
        char mode;
        int trid, item;
        map<int, bool> blocked;
        while(scanf("%c %d %d", &mode, &trid, &item) == 3){
            if(blocked.find(trid) != blocked.end())
                printf("IGNORED\n");
            else if(type.find(item) != "X")
        }

    }

    return 0;
}