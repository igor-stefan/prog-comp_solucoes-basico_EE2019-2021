#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void direction(char letter, int& i, int& j){
    // cout << "letter = " << letter << "\n";
    switch(letter){
        case 'N':
            i += dy[0];
            j += dx[0];
            break;
        case 'E':
            i += dy[1];
            j += dx[1];
            break;
        case 'S':
            i += dy[2];
            j += dx[2];
            break;
        case 'W':
            i += dy[3];
            j += dx[3];
            break;
        default:
            i += 0;
            j += 0;
    }
}

int earliestTime(char a[], int n, int sx, int sy, int ex, int ey, int moves){
    if(moves > n or (ex == sx and ey == sy))
        return moves;
    int moved_x = sx, moved_y = sy;
    long long new_distance_x, actual_distance_x, new_distance_y, actual_distance_y;
    actual_distance_x = abs(ex - sx);
    actual_distance_y = abs(ey - sy);
    direction(a[moves], moved_y, moved_x);
    if(moved_x == ex and moved_y == ey)
        return moves;
    new_distance_x = abs(ex - moved_x);
    new_distance_y = abs(ey - moved_y);
    if(new_distance_x < actual_distance_x or new_distance_y < actual_distance_y )
        return earliestTime(a, n, moved_x, moved_y, ex, ey, moves + 1);
    return earliestTime(a, n, sx, sy, ex, ey, moves + 1);
}

// int earliestTime2(char a[], int n, int sx, int sy, int ex, int ey){
//     unsigned long long actual_distance, new_distance;
//     int moved_x = sx, moved_y = sy, i;
//     for(i = 1; i <= n; i++){
//         moved_x = sx, moved_y = sy;
//         actual_distance = 1LL * (ex - sx) * (ex - sx) + (ey - sy) * (ey - sy);
//         direction(a[i], moved_y, moved_x);
//         // cout << "moved_x = " << moved_x << " moved_y = " << moved_y << "\n";
//         // cout << "new distance = " << new_distance <<" actual_distance = " << actual_distance << "\n";
//         if(moved_x == ex and moved_y == ey)
//             break;
//         new_distance = 1LL * (ex - moved_x) * (ex - moved_x) + (ey - moved_y) * (ey - moved_y);
//         if(new_distance < actual_distance){
//             actual_distance = new_distance;
//             sx = moved_x;
//             sy = moved_y;
//         }
//     }
//         return i;
// }

int main(){
    int t, sx, sy, ex, ey;
    char wind[Nmax];
    scanf("%d %d %d %d %d", &t, &sx, &sy, &ex, &ey);
    for(int i = 1; i <= t; i++)
       cin >> wind[i];
    int seconds = earliestTime(wind, t, sx, sy, ex, ey, 1);
    if(seconds > t)
        printf("-1\n");
    else
        printf("%d\n", seconds);
    return 0;
}
