#include<bits/stdc++.h>
// https://codeforces.com/problemset/problem/768/C
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
int main(int argc, char const *argv[])
{
   ll n,k,x;
   cin>>n>>k>>x;
   std::vector<ll>Freq(1500,0);
   std::vector<ll>dp(1500,0);
   while (n--){
       ll x;
       cin>>x;
       Freq[x]++;
   }
   while(k--){
       for(int i=0;i<1500-1;i++){
           dp[i]=Freq[i];
       }
       int parity=0;
       for(int i=0;i<1500-1;i++){
           if(Freq[i]>0){
               ll current=i^x;
               ll delta=Freq[i]/2;
               if(parity==0){
                   delta+=(Freq[i]&1);
               }
               dp[i]-=delta;
               dp[current]+=delta;
               parity=parity^(Freq[i]&1);
           }
       }
       for(int i=0;i<1500-1;i++){
          Freq[i]=dp[i];
       }
   }
   int min_val=INT_MAX,max_val=INT_MIN;
   for(int i=0;i<1500-1;i++){
           if(Freq[i]>0){
               min_val=min(i,min_val);
               max_val=max(i,max_val);
           }
    }
    cout<<min_val<<" "<<max_val<<"\n";
    return 0;
}
