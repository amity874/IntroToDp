#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[])
{
    int n,m;
    std::cin>>m>>n;
    std::vector<std::vector<ll>>dp(m,std::vector<ll>(n,1));
    dp[m-1][n-1]=1;
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=dp[i][j+1]+dp[i+1][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            std::cout<<dp[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<dp[0][0];
return 0;
}