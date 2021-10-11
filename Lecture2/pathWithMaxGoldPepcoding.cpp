#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[])
{
    ll n;
    ll m;
    std::cin>>n>>m;
    std::vector<std::vector<ll>>dp(n,std::vector<ll>(m,0));
    std::vector<std::vector<ll>>arr(n,std::vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>arr[i][j];
        }
    } 
    for(int j=m-1;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            if(j==m-1){//last column
                dp[i][j]=arr[i][j];
            }
            else if(i==0){//first row
            dp[i][j]=arr[i][j]+std::max(dp[i][j+1],dp[i+1][j+1]);
            }
            else if(i==n-1){
                dp[i][j]=arr[i][j]+std::max(dp[i][j+1],dp[i-1][j+1]);
            }
            else{
            dp[i][j]=std::max({dp[i][j+1],dp[i-1][j+1],dp[i+1][j+1]})+arr[i][j];
            }
        }
    }
    ll max=dp[0][0];
    for(int i=1;i<n;i++){
        max=std::max(max,dp[i][0]);
    }
    std::cout<<max;
return 0;
}