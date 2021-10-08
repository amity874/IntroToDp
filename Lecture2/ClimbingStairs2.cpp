#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::vector<int>dp(n+1,0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=arr[i]&&i+j<dp.size();j++){
            dp[i]+=dp[i+j];
        }
    }
    std::cout<<dp[0];
return 0;
}