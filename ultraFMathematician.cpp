#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e2 + 3;

int main (){
	string a, b;
	int c[Nmax];
	cin >> a >> b;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == b[i])
			c[i] = 0;
		else c[i] = 1;
	}
	for(int i = 0; i < a.size(); i++)
		cout << c[i];
	printf("\n");
	return 0;
}
