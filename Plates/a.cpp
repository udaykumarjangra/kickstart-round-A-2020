#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,p;
ll a[55][35];
ll cache[55][1505];
ll solve(int stack, int taken)
{	if(taken==0)
	{
		return 0;
	}
	if(taken<0)
	{
		return -2e9;
	}
	if(stack>n)
	{
		return 0;
	}
	if(cache[stack][taken]!= -1)
	{
		return cache[stack][taken];
	}
	ll ans=0;
	ll val=0;
	for(int i=0; i<=k; i++)
	{
		val+=a[stack][i];	
		ans=max(ans, val+solve(stack+1,taken-i));
		cache[stack][taken]=ans;
	}
	return ans;	
}
int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int tc;
	cin>>tc;
	for(int t=1; t<=tc; t++)
	{
		cin>>n>>k>>p;
		memset(cache,-1,sizeof(cache));
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=k; j++)
			{
				cin>>a[i][j];
			}
		}
		ll ans=solve(1,p);
		cout<<"Case #"<<t<<": "<<ans<<"\n";
	}
	return 0;
}
