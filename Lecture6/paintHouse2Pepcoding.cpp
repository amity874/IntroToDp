#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[])
{
    //tc->o(n^3)
    ll n,k;//n=>no of house,m=>color
    std::cin>>n>>k;
    ll arr[n][k];
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            std::cin>>arr[i][j];
        }
    }
    ll dp[n][k];
    for(int j=0;j<k;j++){//Base cases
        dp[0][j]=arr[0][j];
    }
   for(int i=1;i<n;i++){
       for(int j=0;j<k;j++){
           int m=INT_MAX;
           for(int x=0;x<k;x++){
               if(j!=x){
                   if(dp[i-1][x]<m){
                       m=dp[i-1][x];
                   }
               }
           }
           dp[i][j]=arr[i][j]+m;
       }
   }
   ll m=INT_MAX;
   for(int x=0;x<k;x++){
       m=std::min(m,dp[n-1][x]);
   }
   std::cout<<m;
return 0;
}