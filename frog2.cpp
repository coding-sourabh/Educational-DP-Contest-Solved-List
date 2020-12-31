#include<bits/stdc++.h> 
using namespace std;
#define vi               vector<int>
#define pii              pair<int,int>
#define vpii             vector<pii>
#define vs               vector<string>
#define si               set<int>
#define ff               first
#define ss               second
#define mii              map<int,int>
#define umii             unordered_map<int,int>
#define p_b              push_back
#define pqi               priority_queue<int>
#define rep(i,a,b)      for(int i=a;i<b;i++)
#define setbits(x)       __builtint_popcountll(x) //return no. of set bits in x
#define zerobits(x)      __buitlin_ctzll(x)       // return no. of zeroes after first set bit
#define int              long long
#define float            double
#define endl             "\n"
#define all(x)           x.begin() , x.end()
#define rall(x)          x.rbegin() , x.rend()
#define line             cout<<"\n";
#define io          	 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define print(try)       for(auto x : try)	cout<<x<<" ";
#define multipletest     int t;cin>>t;while(t--) 
#define newline          cout<<endl;

void consistency_patience_self_believe()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
	   freopen("input1.txt","r",stdin);
	   freopen("output1.txt","w",stdout);
	#endif
}

const int mod = 100000000;

void add(int &a , int &b) {  a = (a+b)%mod; }

void subtract(int &a , int &b) { a = (a-b + mod) % mod;}

void multiply(int &a , int &b) { a = ( ( (a%mod) * (b%mod))%mod );}

bool isPrime(int n){if(n==1){return false;}if(n==2){return true;}if(n%2==0){return false;}for(int i = 3; i <= sqrt(n); i+=2){if(n % i == 0){return false;}}return true;}

long long binpow(long long a, long long b) {long long res = 1; while (b > 0) { if (b & 1) res = res * a;a = a * a;b >>= 1;}return res;}

int getHighestSetBit(int n){int cnt=0;while(n){n/=2;cnt++;}return cnt;}

// for GCD -> __gcd(a,b);
 
int LCM(int x , int y) { return (x * y)/__gcd(x,y); }

void q1();  void q2();  void q3(); void q4(); void q5();  void q6();

// const int N = 10;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////f//////////////////////////////////////////////////////////////////////////////

int32_t main()
{
	consistency_patience_self_believe();
	io

    // multipletest
     q1();
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
