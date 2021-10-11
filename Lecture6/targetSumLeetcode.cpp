#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[]){
    ll n;
    std::cin>>n;
    ll s;
    std::cin>>s;
    std::vector<ll>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum<s||(sum+s)%2!=0 ||(sum+s)<0){
        return 0;
    }
    ll m=(sum+s)/2;
    std::vector<std::vector<ll>>dp(n+1,std::vector<ll>(m+1));
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else if(j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                dp[i][j]=0;
            }
            else{
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            std::cout<<dp[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<dp[n][m];
return 0;
}