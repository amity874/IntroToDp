#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
int main(int argc, char const *argv[]){
int t;
	cin>>t;
	while(t--) {
		ll n, k;
		cin>>n>>k;
		vi h(n);
		loop(i, 0, n-1) cin>>h[i];
		vi dp(n, inf);
		// dp[i] -> min cost to reach from 0-i
		dp[0] = 0;
		loop(i, 1, n-1) {
			loop(j, 1, k) {
				if(i - j < 0) break;
				dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
			}
		}
		// logarr(dp, 0, n-1);
		cout<<dp[n-1]<<endl;
	}
return 0;
}