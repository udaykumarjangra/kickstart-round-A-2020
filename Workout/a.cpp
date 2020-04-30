#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll a[100005];
bool ch(ll mid)
{
	ll sessions=0;
	for(ll i=1; i+1<=n; i++)
	{
		sessions+=(a[i+1]-a[i]-1)/mid;
	}
	if(sessions<=k)
	{
		return true;
	}
	else{
		return false;
	}
}

ll solve()
{
	ll l=1, hi=1e9;
	
	while(l<hi)
	{	
		ll mid=(l+hi)/2;
		if(ch(mid))
		{
			hi=mid;
		}
		else{
			l=mid+1;
		}
	}
	return l;
}
int main()
{	
	ll t;
	cin>>t;
	for(ll tc=1; tc<=t; tc++)
	{
		cin>>n>>k;
		for(ll i=1; i<=n; i++)
		{
			cin>>a[i];
		}
		ll ans=solve();
		cout<<"Case #"<<tc<<": "<<ans<<endl;
	}
	return 0;
}
