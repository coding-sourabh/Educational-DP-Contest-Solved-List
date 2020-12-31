#include<bits/stdc++.h> 
using namespace std;

#define ff first
#define ss second
#define pii pair<int,int>

void consistency_patience_self_believe()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
	   freopen("input1.txt","r",stdin);
	   freopen("output1.txt","w",stdout);
	#endif
}


void runTestCases()
{
    int n,W;
    cin>>n>>W;
    
    vector<long long> w(n) , value(n);

    for(int i=0 ;i < n; i++)
        cin>>w[i]>>value[i];

    long long dp[n+1][W+1];
    
    for(int i=0 ; i <= n ; i++)
    {
       for(int j=0 ; j <= W ; j++)
       {
          if(i == 0 || j == 0) dp[i][j] = 0;

          else if(w[i-1] <= j)
          {
             dp[i][j] = max(dp[i-1][j-w[i-1]] + value[i-1] , dp[i-1][j]);
          }
          else
          {
             dp[i][j] = dp[i-1][j];
          }
       }
    }

    cout<<dp[n][W]<<endl;
}

int32_t main()
{
	consistency_patience_self_believe();

    // multipletest
     runTestCases();
}
