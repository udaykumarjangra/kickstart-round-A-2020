#include<bits/stdc++.h>
using namespace std;
#define ll long long
int N = 51;
int K = 31;
int arr[50][30];
int sum[51][1501];
int n,k,p;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin>>tc;
	for(int t=0; t<tc; t++)
	{
		memset(arr,0,sizeof(arr));
		memset(sum,0,sizeof(sum));
		sum[0][0]=0;
		cin>>n>>k>>p;
		for(int i=0; i<n; i++)
		{	memcpy(sum[i+1],sum[i],sizeof(sum[0]));
			for(int j=0, s=0; j<k; j++)
			{
				cin>>arr[i][j];
				s+=arr[i][j];
				for(int l=0; l+j+1<=p; l++)
				{
					sum[i+1][l+j+1]=max(sum[i][l]+s,sum[i+1][l+j+1]);
				}
			}
		}
		cout<<"Case #"<<t+1<<": "<<sum[n][p]<<endl;
	}
}
