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
  string s,t;
  cin>>s>>t;
  
  int n = s.size() , m = t.size();

  int dp[n+1][m+1];

  for(int i=0 ;i <= n ; i++)
  {
     for(int j=0; j <= m ; j++)
     {
        if(i == 0 || j == 0) 
           dp[i][j] = 0;

        else if(s[i-1] == t[j-1])
           dp[i][j] = dp[i-1][j-1] + 1;
        
        else
           dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
     }
  }


  int i = n , j = m;
  string ans = "";

  while(i > 0 && j > 0)
  {
     int y = dp[i-1][j] , z = dp[i][j-1];

     if(s[i-1] == t[j-1]){
      ans += s[i-1];
      i--; j--;
    }

    else if(y > z)
      i--;
    else
      j--;

  }
  
  reverse(ans.begin(), ans.end());
  cout<<ans<<endl;

}

int32_t main()
{
	consistency_patience_self_believe();

    // multipletest
     runTestCases();
}
