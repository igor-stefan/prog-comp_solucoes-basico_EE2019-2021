#include <bits/stdc++.h>

using namespace std;
const double PI = 3.14159265;

int main(){
    const double a = 0.1;
    const double m = 0.5;
    double t;
    while(cin >> t){
        printf("t = %.2f ", t);
        double x = a * cos(PI * t);
        double v = -a * PI * sin(PI * t);
        double ac = -a * PI * PI * cos(PI * t);
        double ec = 0.5 * m * v * v;
        double ep = 0.5 * 0.5 * PI * PI * x * x;
        double soma = abs(ec) + abs(ep);
        printf("x = %.6f v = %.6f ac = %.6f ec = %.6f ep = %.6f soma = %.6f\n\n", x, v, ac, ec, ep, soma); 
    }
    return 0;
}