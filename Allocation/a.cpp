#include<bits/stdc++.h>
using namespace std;
int fun(vector <int> arr, int budget)
{
	int total=0;
	sort(arr.begin(), arr.end());
	int i=0;
	while(budget>0)
	{
		if(budget-arr[i]>=0)	
		{
			total++;
			budget=budget-arr[i];
			if(i==arr.size()-1)
			{
				break;
			}
			i++;
		}
		else if( budget-arr[i]<0)
		{
			break;
		}
	}
	return total;
}
int main()
{
	int t;
	cin>>t;
	for(int test=0; test<t; test++)
	{
		int no, budget;
		cin>>no>>budget;
		vector <int> arr(no);
		for(int i=0; i<no; i++)
		{
			cin>>arr[i];
		}
		int ans;
		ans=fun(arr,budget);
		cout<<"Case #"<<test+1<<": "<<ans<<endl;
	}
	return 0;
}
