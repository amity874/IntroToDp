#include<bits/stdc++.h>
// https://www.spoj.com/problems/MPILOT/en/
#define ll long long int
ll n;
std::vector<ll>cap(10005,0);
std::vector<ll>ass(10005,0);
std::vector<std::vector<ll>>dp(10005,std::vector<ll>(5005,-1));
ll calc(int a,int c,int i){
    if(dp[i][a]!=-1){
        return dp[i][a];
    }
   if(i==n){
       return 0;
   }
   if(a==n/2){
       return dp[i][a]=calc(a,c+1,i+1)+cap[i];
   }
   else if(a==c){
       return dp[i][a]=calc(a+1,c,i+1)+ass[i];
   }
   else{
       return dp[i][a]=std::min(calc(a+1,c,i+1)+ass[i],calc(a,c+1,i+1)+cap[i]);
   }
}
int main(int argc, char const *argv[])
{
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>cap[i]>>ass[i];
    }
    dp[0][0]=ass[0]+calc(1,0,1);
    std::cout<<dp[0][0];
return 0;
}