#include <iostream>

using namespace std;

const int Nmax = 1e2 + 3;

int main(){
    int n, m;
    int a[Nmax][Nmax];
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j<= m; j++)
            cin >> a[i][j];

    for(int j = 0; j <= m + 1; j++){
        a[0][j] = 'k';
        a[n + 1][j] = 'k';
    }
    for(int j = 0; j <= m + 1; j++){
        a[j][0] = 'k';
        a[j][m + 1] = 'k';
    }
    int i, j;
    for(i = 1; i <= n; i++){
        bool flag = false;
        for(j = 1; j <= m; j++){
            if(a[i][j] == 4){
                printf("true\n");
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    cout << "i = " << i << " j = " << j << "\n";
    return 0;
}