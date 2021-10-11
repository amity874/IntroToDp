#include<bits/stdc++.h>
#define ll long long int
#define inf 1e18
int main(int argc, char const *argv[])
{
    ll n;
    std::cin>>n;
    std::vector<ll>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::vector<ll>dp(n,0);
    dp[0]=arr[0];
    dp[1]=arr[1];
    for(int i=2;i<n;i++){
        dp[i]=std::min(dp[i-1],dp[i-2])+arr[i];
    }
    std::cout<<std::min(dp[n-1],dp[n-2]);
    return 0;
}