#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<int>arr(n,0);
 
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    sum/=2;
    std::vector<std::vector<int>>dp(n,std::vector<int>(sum+1));
    dp[0][0]=true;
    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            if(arr[i]>j){
            dp[i][j]=dp[i-1][j];
            } 
            else{
                if(dp[i-1][j-arr[i]]){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    bool ans=dp[n-1][sum];
    if(ans){
        std::cout<<true;
    }
    else{
       std::cout<<false;
    }
return 0;
}