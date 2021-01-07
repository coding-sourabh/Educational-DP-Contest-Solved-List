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
  int n;
  cin>>n;

  vector<double> a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];

  vector<vector<double>> dp(n+1 , vector<double>(3000 , 0));

  //dp[x][y] = when we have x+1 coin what is the  probability of getting y heads.
  
  dp[0][0] =  (1 - a[0]);   // only one coin and we got tail
  dp[0][1] =   a[0];  // only one coin and we got head
  
  for(int i = 1 ; i < n ; i++)
  {
     for(int j = 0 ; j < 3000 ; j++ )
     {
        // tail
         dp[i][j] += (1 - a[i]) * dp[i-1][j];  // we got our j heads at i-1 , becoz it is tails.


        //head
         if(j > 0)
         dp[i][j] += a[i] * dp[i-1][j-1]; //we got our jth head at this ith position so we need j-1 head prob. from i-1 coins
     }
  }
  double ans = 0;
  for(int i=n/2+1 ;i < 3000 ; i++)
  {
    ans += dp[n-1][i]; // all the prob. in which we are getting more than n/2 coins as heads when we are reaching last
  }

  cout<<setprecision(10)<<ans<<endl;
}
int32_t main()
{
	consistency_patience_self_believe();

    // multipletest
     runTestCases();
}
