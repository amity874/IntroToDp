#include<bits/stdc++.h>
using namespace std;
int fibdp(int n,std::vector<int>&dp){
    if(n==0 or n==1){//o(1) time
        return n;
    }
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fibdp(n-1,dp)+fibdp(n-2,dp);
}
int buttumUpdp(int n){
    std::vector<int>dp(n+1,0);
    dp[0];
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(int argc, char const *argv[]){
    int n;
    cin>>n;
    std::vector<int>dp(n+1,-1);
    cout<<buttumUpdp(n);
return 0;
}