#include <bits/stdc++.h>
#define N 100100
#define ll long long 

using namespace std;

ll n,p;
int a[26];

int main()
{
	ios_base::sync_with_stdio(0);
	
	for(int i=0;i<26;i++)
	{
		if(i==25)
			a[i]=16;
		else if(i>=20)
			a[i]=10+i-20+1;
		else if(i>=15)
			a[i]=10;
		else if(i>=10)
			a[i]=6+i-10;
		else if(i>=5)
			a[i]=5;
		else a[i]=i+1;
	}
	while(cin>>n && n!=-1)
	{
		bool c=true;
		ll ans=0;
		if(n<=25)
			cout<<a[n]<<"\n";
		else
		{
		while(n>25)
		{
			ll p=1;
			ll cnt=0;
			int t=1;
			ll a=1;
			while(p*5<=n)
			{
                cout << "p = " << p << "\n";
                cout << "a = " << a << "\n";
				if(t%2==1)
					a*=5;
				else
					a=3*a+2*(p-a);
				cout << "t = " << t << "\n";
				cnt+=p;
				t++;
				p*=5;
                cout << "cnt = " << cnt << "\n";
                cout << "a = " << a << "\n";
			}
			if(c)
				ans+=a;
			else ans+=p-a;
			if(cnt%2==1)
				c=!c;
			n-=p;	
		}
		if(c)
			ans+=a[n];
		else
			ans+=n+1-a[n];
		cout<<ans<<endl;
	}
	}
	return 0;
}