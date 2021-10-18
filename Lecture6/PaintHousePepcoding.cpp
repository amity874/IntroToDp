#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[]){
    ll n;
    std::cin>>n;
    std::vector<std::vector<ll>>dp(n,std::vector<ll>(3,0));
    ll r,g,b;
    std::cin>>r>>g>>b;
    dp[0][0]=r;
    dp[1][0]=g;
    dp[2][0]=b;
    for(int i=1;i<n;i++){
        std::cin>>r>>g>>b;
        dp[0][i]=r+std::min(dp[1][i-1],dp[2][i-1]);
        dp[1][i]=g+std::min(dp[2][i-1],dp[0][i-1]);
        dp[2][i]=b+std::min(dp[1][i-1],dp[0][i-1]);
    }
    std::cout<<std::min({dp[0][n-1],dp[1][n-1],dp[2][n-1]});    
return 0;
}