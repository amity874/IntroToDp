#include<bits/stdc++.h>
#define ll long long int
#define inf 1e18
int main(int argc, char const *argv[]){
    ll n;
    std::cin>>n;
    std::vector<ll>arr(n);
    for(int i=0;i<n;i++){
    std::cin>>arr[i];
    }
   std::vector<ll>dp(n+1,inf);
   dp[n]=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]!=0){
            for(int j=1;j<=arr[i]&&j<dp.size();j++){
                if(i+j<dp.size()){
                dp[i]=std::min(dp[i],dp[i+j]);
                }
            }
            dp[i]+=1;
        }
        else{
            dp[i]=inf;
        }
    }
    std::cout<<dp[0];
return 0;
}