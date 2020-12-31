#include<bits/stdc++.h> 
using namespace std;

void consistency_patience_self_believe()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
	   freopen("input1.txt","r",stdin);
	   freopen("output1.txt","w",stdout);
	#endif
}


void q1()
{
	int n;
	cin>>n;

	vector<int> a(n);

	for(int i=0;i<n;i++)
		cin>>a[i];

	int dp[n] = {0};

	dp[0] = 0;
	dp[1] = abs(a[1] - a[0]);

	for(int i=2 ; i < n ; i++)
	{
		if( dp[i-1] + abs(a[i] - a[i-1]) <= dp[i-2] + abs(a[i] - a[i-2]) )   // if cost of previous stone is less
			dp[i] = dp[i-1] + abs(a[i] -  a[i-1]);
		else
			dp[i] = dp[i-2] + abs(a[i] - a[i-2]);   
	}

	cout<<dp[n-1]<<endl;
}

int32_t main()
{
	consistency_patience_self_believe();

    // multipletest
     q1();
}
