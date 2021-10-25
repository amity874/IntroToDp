#include<bits/stdc++.h>
#define ll long long int

int main(int argc, char const *argv[])
{
    // tc->o(n^2)
     ll n,k;//n=>no of house,m=>color
    std::cin>>n>>k;
    ll arr[n][k];
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            std::cin>>arr[i][j];
        }
    }
    ll dp[n][k];
    int f_min=INT_MAX;
    int s_min=INT_MAX;
   for(int j=0;j<k;j++){
       dp[0][j]=arr[0][j];
       if(arr[0][j]<=f_min){
           s_min=f_min;
           f_min=arr[0][j];
       }
       else if(arr[0][j]<=s_min){
           s_min=arr[0][j];
       }
   }
    for(int i=1;i<n;i++){
    int new_min1=INT_MAX;
    int new_min2=INT_MAX;
        for(int j=0;j<k;j++){
        if(dp[i-1][j]==f_min){
                dp[i][j]=s_min+arr[i][j];
            }
        else{
                dp[i][j]=f_min+arr[i][j];
            }

        if(dp[i][j]<=new_min1){
           new_min2=new_min1;
           new_min1=dp[i][j];
       }
       else if(dp[i][j]<=new_min2){
           new_min2=dp[i][j];
       }
    }
    f_min=new_min1;
    s_min=new_min2;
    }
    std::cout<<f_min;
return 0;
}