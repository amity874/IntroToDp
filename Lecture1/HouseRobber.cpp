#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int houseRobberTD(int n ,std::vector<int>&v){
    if(n==0)return v[0];
    if(n==1)return std::max(v[1],v[0]);
    if(dp[n]!=-1) return dp[n];
    return dp[n]=std::max(houseRobberTD(n-1,v),v[n]+houseRobberTD(n-2,v));
}
int houseRobberBU(int n,std::vector<int>&v){
    std::vector<int>dp(n,0);
    dp[0]=v[0];
    dp[1]=max(v[0],v[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],v[i]+dp[i-2]);
    }
    return dp[n-1];
}
int main(int argc, char const *argv[]){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
        std::vector<int>arr(n,0);
        for(int i=0;i<n;i++){
        cin>>arr[i];
        }
        cout<<houseRobberBU(n,arr)<<"\n";
return 0;
}