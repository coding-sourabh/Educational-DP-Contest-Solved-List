// The main difference between this and the D knapsack is the constraints ranges, in previous one the W is 10^5 so
// we defined our dp in the form of W , but here it is 10^9 , so in this version it will definitely give TLE as 10^9 * 10^2 = 10 ^11
// But the max ans can range here only to the sumbmission of all a[i] , so we made our dp acco  

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
    int n,W, sum = 0;
    cin>>n>>W;
    
    vector<int> w(n) , values(n);

    for(int i=0 ;i < n ;i++)
    {
      cin>>w[i]>>values[i];
      sum += values[i];
    }

    vector<long long> dp(sum+1 , 1e18);
    
    dp[0] = 0;

    // dp[i] : Stores the minimum weight required to get the total value exactly as j.
    
    for(int i=1 ; i <= n ; i++)
    {
       for(int j = sum - values[i-1] ; j >= 0  ; j--)
       {
          dp[j + values[i-1]] = min(dp[j] + w[i-1] , dp[j + values[i-1]]);  // To get to the jth value either choose the previous       
       }                                                                    //one or include the ith weight and get to that value
    }                                                                       // the minimum weight fom both of them will get stored in the dp[j].
    
    int ans = 0;
    
    for(int i=0 ;i <= sum ; i++)
    {
        if(dp[i] <= W)
          ans = max(i , ans);
    }

    cout<<ans<<endl;
}

int32_t main()
{
	consistency_patience_self_believe();

    // multipletest
     runTestCases();
}
