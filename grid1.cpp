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

void runTestCases()
{
  int n , m ;
  cin>>n>>m;

  char a[n][m];
  int dp[n][m];

  for(int i = 0 ; i < n ; i++)
    for(int j=0 ;j < m ; j++)
      cin>>a[i][j] , dp[i][j] = 0;

    
    dp[0][0] = 1;

    for(int i=0 ; i < n ; i++)
    {
      for(int j=0 ;j < m ; j++)
      {
        if(a[i][j] == '#') continue;

        if(i+1 < n && a[i+1][j] == '.') dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % 1000000007;
          if(j+1 < m && a[i][j+1] == '.') dp[i][j+1] = (dp[i][j+1] + dp[i][j] ) % 1000000007;  
      }
    }
    
    cout<<dp[n-1][m-1];
  
}

int32_t main()
{
	consistency_patience_self_believe();

    // multipletest
     runTestCases();
}
