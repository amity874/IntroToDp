#include<bits/stdc++.h>
#define ll long long int
ll matMulRec(std::vector<ll>&arr,int i,int j){
  if(i==j){
      return 0;
  }
  ll ans=INT_MAX;
  for(int k=i;k<=j-1;k++){
     ans=std::min({ans,matMulRec(arr,i,k)+matMulRec(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]});
  }
  return ans;
}
ll dp[10005][10005];
ll matMulRecTopd(std::vector<ll>&arr,int i,int j){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        ans=std::min({ans,matMulRec(arr,i,k)+matMulRec(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]});
    }
    return dp[i][j]=ans;
}
ll matMulRecButtomUp(std::vector<ll>arr){
   int n=arr.size();
   std::vector<std::vector<ll>>dp(n,std::vector<ll>(n,0));
   for(int i=0;i<n;i++){
       dp[i][i]=0;
   }
    // for(int i=0;i+len<=n;i++){
   for(int len=2;len<n;len++){
       for(int i=1;i<=(n-len);i++){
           int j=(len+i)-1;
           if(j==n)continue;
           dp[i][j]=INT_MAX;
           for(int k=i;k<=j-1;k++){
               dp[i][j]=std::min({dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]});
           }
       }
   }
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           std::cout<<dp[i][j]<<" ";
       }
       std::cout<<"\n";
   }
   return dp[1][n-1];
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    std::vector<ll>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    std::cout<<matMulRecButtomUp(arr);
return 0;
}