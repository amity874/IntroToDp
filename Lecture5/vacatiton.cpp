#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<std::vector<int>>dp(3,std::vector<int>(n,0));
    int a,b,c;
    std::cin>>a>>b>>c;
    dp[0][0]=a;
    dp[1][0]=b;
    dp[2][0]=c;
    for(int i=1;i<n;i++){
        std::cin>>a>>b>>c;
        dp[0][i]=a+std::max(dp[1][i-1],dp[2][i-1]);
        dp[1][i]=b+std::max(dp[0][i-1],dp[2][i-1]);
        dp[2][i]=c+std::max(dp[0][i-1],dp[1][i-1]);
    }
    std::cout<<std::max({dp[0][n-1],dp[1][n-1],dp[2][n-1]});
return 0;
}