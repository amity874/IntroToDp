#include<bits/stdc++.h>
using namespace std;
#define mod             1000000007

#define vi              vector<ll>
#define mod             1000000007
#define ll 				long long int
#define vs				vector<string>
#define pii             pair<ll,ll>
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
int main(int argc, char const *argv[]){
    ll n, x;
	cin>>n>>x;
	vi coin(n);
	loop(i, 0, n-1) cin>>coin[i]; // sorted fashion
	vi dp(x+1,0);
	dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(coin[j]>i)continue;
            dp[i]=(dp[i]+dp[i-coin[j]])%mod;
        }
    }
	cout<<dp[x]%mod;
return 0;
}