#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N =1e5+5;
ll n,k;
string a[N];
typedef struct node{
	struct node *child[26];
	ll count;
}trie;
trie *root;
void insert(string &a)
{	trie * cur=root;
	for(ll i=0; i<a.length(); i++)
	{
		char ch=a[i];
		ll c=ch-'A';
		if(!cur->child[c])
		{
			cur->child[c]=new trie();
		}
		cur=cur->child[c];
	}
	cur->count++;
}
ll ans=0;
void solve(trie *root, ll level)
{trie *cur=root;
	for(ll i=0; i<26; i++)
	{
		
		if(cur->child[i])
		{
			solve(cur->child[i], level+1);
			cur->count+=cur->child[i]->count;
		}
	}
	while(cur->count>=k)
	{
		cur->count-=k;
		ans=ans+level;
	}
}
int main()
{	
	ll t;
	cin>>t;
	for(ll tc=1; tc<=t; tc++)
	{	root=new trie();
		ans=0;
		cin>>n>>k;
		for(ll i=0; i<n; i++)
		{
			cin>>a[i];
			insert(a[i]);
		}
		solve(root,0);
		cout<<"Case #"<<tc<<": "<<ans<<endl;
	}
	return 0;
}
