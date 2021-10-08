#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[])
{
    ll n;
    std::cin>>n;
    std::vector<ll>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(i==1){
        dp[i]=dp[i-1];
        }
        else{
            dp[i]+=dp[i-1]+dp[i-2];
        }
    }
std::cout<<dp[n];
return 0;
}