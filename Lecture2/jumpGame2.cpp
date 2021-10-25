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
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
int main(int argc, char const *argv[])
{
    std::vector<ll>arr={3,3,0,2,1,2,4,2,0,0};
   int n=arr.size();
       vector<ll>dp(n,INT_MAX);
       dp[0]=0;
       for(int i=1;i<n;i++){
           for(int j=1;j<=arr[i];j++){
               if(i-j<0)break;
               dp[i]=std::min(dp[i],dp[i-j])+1;
           }
        }
       logarr(dp,0,10);
       cout<<dp[n-1];
    return 0;
}
