#include<bits/stdc++.h>
#define ll long long int
bool isItSafe(int i,int j,std::vector<std::vector<ll>>&dp){
    return (i>=0 && i<dp.size()&& j>=0 && j<dp.size());
}
int main(int argc, char const *argv[])
{
    ll m,n;
    std::cin>>n>>m;
    std::vector<std::vector<ll>> dp(m,std::vector<ll>(n,0));
    for(int j=n-1;j>=0;j--){
        for(int i=m-1;i>=0;i--){
            if(j==n-1&&i==m-1){
                dp[i][j]=std::max({dp[i][j-1],dp[i-1][j]});
            }
            else if(j==n-1){
                 if(j==n-1 && i==0){
                    dp[i][j]=std::max(dp[i][j-1],dp[i+1][j]);
                }
                dp[i][j]=std::max({dp[i][j-1],dp[i+1][j],dp[i-1][j]});
            }
            else if(i==0){
                if(i==0 && j==n-1){
                    continue;
                }
                dp[i][j]=std::max(dp[])
            }

        }
    }
return 0;
}