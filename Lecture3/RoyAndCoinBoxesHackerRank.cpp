#include<bits/stdc++.h>
// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1
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
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
using namespace std;
ll start[1000006],end_[1000006],dp[1000006],coins[1000006];
int main(int argc, char const *argv[]){
    for(int i=0;i<=1000000;i++){
        start[i]=end_[i]=dp[i]=coins[i]=0;
    }
    ll n,m;//no of coins and days
    cin>>n>>m;
    while(m--){
        ll l,r;
        cin>>l>>r;
        start[l]++;
        end_[r]++;
    }
    dp[1]=start[1];
    for(int i=2;i<=n;i++){
        dp[i]=start[i]-end_[i-1]+dp[i-1];//difference array trick to process query
    }
    for(int i=1;i<=n;i++){
        coins[dp[i]]++;
    }
    for(int i=n-1;i>=1;i--){
        coins[i]+=coins[i+1];
    }
    ll q;
    cin>>q;
    while (q--){
        ll a;
        cin>>a;
        cout<<coins[a]<<"\n";
    }
return 0;
}