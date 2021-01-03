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



vector<int> gr[100001];
int n,m;

vector<int> dist(100001 , 0);

int max_length(int cur)
{
   if(dist[cur] != 0) return dist[cur];   // Already calculated the max distance from this node

   if(gr[cur].size() == 0) return 0;     // last node of the path

   int maxi = 0;

   for(auto nodes : gr[cur])
      maxi = max( max_length(nodes) , maxi);   // maxi stores maximums of all the paths
  
   return dist[cur] = maxi + 1;         // +1 for including current node in the path

}

void runTestCases()
{
  cin>>n>>m;

  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    gr[u-1].push_back(v-1);
  }
  
  int ans = 0;
  
  for(int i=0; i< n ; i++)    // To cover disconnected graph
      max_length(i);

  cout<<*max_element(dist.begin(), dist.end()) <<endl;
}

int32_t main()
{
	consistency_patience_self_believe();

    // multipletest
     runTestCases();
}
