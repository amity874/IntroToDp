#include<bits/stdc++.h>
#define ll long long int
ll calc(std::vector<ll>&arr){
    int n=arr.size();
   std::vector<std::vector<ll>>dp(n,std::vector<ll>(n,0));
   for(int len=0;len<arr.size();len++){
       for(int i=0,j=len;j<n;i++,j++){
           for(int k=i;k<=j;k++){
               ll left_range=(k==i)?0:dp[i][k-1];
               ll right_range=(k==j)?0:dp[k+1][j];
               ll current_val=arr[k]*((i==0)?1:arr[i-1])*((j==n-1)?1:arr[j+1]);
               dp[i][j]=std::max(dp[i][j],left_range+right_range+current_val);
           }
       }
    //    for (int i = 0; i < n; i++){
    //        for(int j=0;j<n;j++){
    //            std::cout<<dp[i][j]<<" ";
    //        }
    //        std::cout<<"\n";
    //     }
       
   }
return dp[0][n-1];
}
int main(int argc, char const *argv[])
{
    ll t;
    std::cin>>t;
    while (t--){
        ll n;
        std::cin>>n;
        std::vector<ll>arr(n,0);
        for(int i=0;i<n;i++){
            std::cin>>arr[i];
        }
        std::cout<<calc(arr)<<"\n";
    }
return 0;
}