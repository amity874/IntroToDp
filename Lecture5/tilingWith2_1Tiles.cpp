#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>dp(n+1,0);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    std::cout<<dp[n];
return 0;
}