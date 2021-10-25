#include<bits/stdc++.h>
#define ll long long int
int BillBoard(int m,int n,int t,std::vector<int>&Pi,std::vector<int>&Ri){
    std::vector<int>dp(Pi.size(),0);
    dp[0]=Ri[0];
    int ans=0;
   for(int i=1;i<Pi.size();i++){
       int res=0;
       for(int j=0;j<i;j++){
           ll dist=Pi[i]-Pi[j];
           if(dist>t){
               res=std::max(res,dp[j]);
           }
       }
       dp[i]=res+Ri[i];
       ans=std::max(ans,dp[i]);
   }
    return ans;
}
int BillOp(int m,int n,int t,std::vector<int>&Pi,std::vector<int>&Ri){
    std::vector<int>dp(m+1,0);
    std::unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[Pi[i]]=Ri[i];
    }
    dp[0]=0;
    for(int i=1;i<=m;i++){
        if(mp[i]==NULL){
            dp[i]=dp[i-1];
        }
        else{
            int excl=dp[i-1];
            int incl=mp[i];
            if(i>=t+1){
            incl+=dp[i-t-1];
            }
            dp[i]=std::max(excl,incl);
        }
    }
    return dp[m];
}
int main(int argc, char const *argv[])
{
    int m,n;
    std::cin>>m>>n;
    std::vector<int>Pi(n,0);
    std::vector<int>Ri(n,0);
    for(int i=0;i<n;i++){
        std::cin>>Pi[i];
    }
   for(int i=0;i<n;i++){
       std::cin>>Ri[i];
   }
    int t;
    std::cin>>t;
    std::cout<<BillOp(m,n,t,Pi,Ri);
return 0;
}