#include <bits/stdc++.h>

using namespace std;

// const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651;
int main(){

    double a, b, c;
    cin >> a >> b >> c;
    double p = (a + b + c) / 2.0;
    double areaT = sqrt(p * (p - a) * (p - b) * (p - c));
    double raioIns = areaT / p;
    double raioCir = (a * b * c) / (4.0 * areaT);
    double areaCir = (M_PI * raioCir * raioCir) - areaT;
    double areaIns = (M_PI * raioIns * raioIns);
    double Tri = areaT - areaIns;
    printf("%.4f %.4f %.4f\n", areaCir, Tri, areaIns);
    return 0;
}