#include <bits/stdc++.h>

using namespace std;

int main(){
    int h, u, d, f;
    while(scanf("%d %d %d %d", &h, &u, &d, &f) == 4 and h){
        const double fatigue = ((double)f / 100) * u;
        // cout << "fatigue = " << fatigue << "\n";
        double distance = 0;
        int day = 0;
        while(distance <= h and distance >= 0){
            if(++day == 1)
                distance += u;
            else
                if(u - fatigue * (day - 1) > 0)
                    distance += (u - fatigue * (day - 1));
            // cout << "quanto subiu = " << u - fatigue * (day - 1) << "\n";
            if(distance > h)
                break;
            distance -= d;
            // cout << "distance = " << distance << "\n";
        }
        if(distance > 0)
            printf("success on day %d\n", day);
        else
            printf("failure on day %d\n", day);
     }
    return 0;
}