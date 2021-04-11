#include <bits/stdc++.h>

using namespace std;

void sort3(int& a, int& b, int& c){
    if(a < b) swap(a, b);
    if(a < c) swap(a, c);
    if(b < c) swap(b, c);
}

void simpleMolecules(int a, int b, int c){
    // sort3(a, b, c);
    if((a + b + c) % 2)
        printf("Impossible\n");
    else{
        int z = (a + c - b) / 2;
        int x = b - c + z;
        int y = b - a + z;
        if(x >= 0 and y >= 0 and z >= 0)
            printf("%d %d %d\n", x, y, z);
        else    
            printf("Impossible\n");
    }
}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    simpleMolecules(a, b, c);
    return 0;
}
