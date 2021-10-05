#include<bits/stdc++.h>
//https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
# define ll long long int
ll dp[2005][2005][6];
ll a1[2005];
ll a2[2005];
int kOrderedLcs(int n,int m,int k){
    if(k<0){
        return -1e7;
    }
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m][k]!=-1){
        return dp[n][m][k];
    }
    int ans=-1;
    ans=std::max(kOrderedLcs(n,m-1,k),kOrderedLcs(n-1,m,k));
    if(a1[n]==a2[m]){
        ans=std::max(ans,(1+kOrderedLcs(n-1,m-1,k)));
    }
       ans=std::max(ans,1+kOrderedLcs(n-1,m-1,k-1));
    return dp[n][m][k]=ans;
}
int main(int argc, char const *argv[]){
  ll n,m,k;
 std::cin>>n>>m>>k;
  for(int i=1;i<=n;i++){
      std::cin>>a1[i];
  }
  for(int i=1;i<=m;i++){
      std::cin>>a2[i];
  }
  memset(dp,-1,sizeof(dp));
  std::cout<<kOrderedLcs(n,m,k);
return 0;
}