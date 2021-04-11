#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, h; // h < x
    double temp;
    vector<double> valx, valh, ans;
    scanf("%d %d", &x, &h);
    for(int i = 0; i < x; i++)
        scanf("%lf", &temp), valx.push_back(temp);
    for(int i = 0; i < h; i++)
        scanf("%lf", &temp), valh.push_back(temp);
    int indexi = 0, indexj = 0, cont = 0, k = 0;
    bool fora = false;
    for(int amostras = 0; amostras < x + h - 1; amostras++){
        double sum = 0;
        cout << "y[" << k++ << "] => "; 
        for(int i = indexi, j = indexj; i < (int)valh.size() and j >= 0; i++, j--){
            cout << valh[i] * valx[j] << " ";
            sum += valh[i] * valx[j];
        }
        printf("= %g\n", sum);
        indexj++, cont++;
        if(indexj == (int)valx.size())
            indexj--;
        if(fora)
            indexi++;
        else{
            if(cont == (int)valx.size())
                indexi++, cont = 0, fora = true;
        }
        ans.push_back(sum);
    }
    // for(int k = 0; k < x + h - 1; k++)
    //     printf("y[%d] = %.2f\n", k - 3, ans[k]);

    return 0;
}