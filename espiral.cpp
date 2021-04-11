#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, b;
    while(scanf("%lld %lld", &n, &b) == 2){
    double i = min(ceil((double)(b - 4 * n + 4) / 8.0), floor((double)(b - 4 * n - 4) / 8.0));
            
            t -= 4 * n - 8 * i + 4;
            cout << "x = " << x << " y = " << y << "\n";
            if(!flag)
                for(; x < n - i + 1; x++)
                    if(++t == b){
                        flag = true;
                        break;
                    }
            cout <<"t = " << t << " x = " << x << " y = " << y << "\n";
            if(!flag)
                for(; y < n - i + 1; y++)
                    if(++t == b){
                        flag = true;
                        break;
                    }
    
            cout <<"t = " << t << " x = " << x << " y = " << y << "\n";
             if(!flag)
            for(; x > n - i - 2; x--)
                 if(++t == b){
                        flag = true;
                        break;
                    }
            cout << "x = " << x << " y = " << y << "\n";
             if(!flag)
            for(; x > n - i - 1; y--)
                 if(++t == b){
                        flag = true;
                        break;
                    }
            cout << "x = " << x << " y = " << y << "\n";
            printf("%lld %lld\n", y, x);
        }
    }
    return 0;
}