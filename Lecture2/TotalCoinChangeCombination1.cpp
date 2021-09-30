#include<bits/stdc++.h>
using namespace std;
#define vi              vector<ll>
#define ll 				long long int
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
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;		
int main(int argc, char const *argv[]){
    ll n, x;
	cin>>n>>x;
	vi coin(n);
	loop(i, 0, n-1) cin>>coin[i]; // sorted fashion
	vi dp(x+1, 0);
	dp[0] = 1;
	loop(j, 0, n-1) { // looping on coins
		loop(i, 1, x) {
			if(coin[j] > i) continue;
			dp[i] = dp[i] + dp[i - coin[j]];
		}
	}
	cout<<dp[x];
return 0;
}