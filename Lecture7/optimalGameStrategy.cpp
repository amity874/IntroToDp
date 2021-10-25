#include<bits/stdc++.h>
#define mod             1000000007
int game(std::vector<int>&arr){
    int n=arr.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int len=1;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j=(i+len-1);
            int x=(i+2<=j)?dp[i+2][j]:0;
            int y=(i+1<=j-1)?dp[i+1][j-1]:0;
            int z=(i<=j-2)?dp[i][j-2]:0;
            dp[i][j]=std::max(arr[i]+std::min(x,y),arr[j]+std::min(y,z));
      }
    }
    return dp[0][n-1];
}
int main(int argc, char const *argv[]){
    int n;
    std::cin>>n;
    std::vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::cout<<game(arr);
return 0;
}