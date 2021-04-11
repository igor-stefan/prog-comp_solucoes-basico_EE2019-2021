#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    int m, n, a;
    scanf("%i %i %i", &m, &n, &a);
    unsigned long long x = ceil((double) m/a) * ceil((double) n/a) * 1LL;
    printf("%llu\n", x);
    return 0;
}
