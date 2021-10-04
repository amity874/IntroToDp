#include<bits/stdc++.h>
//for submition 
#define ll long long int
int main(int argc, char const *argv[]){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> arr(n,std::vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>arr[i][j];
        }
    }
    ll ans=0;
    std::vector<std::vector<int>> dp(n,std::vector<int>(m,0));
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1){
                dp[i][j]=arr[i][j];
            }
            else if(i==n-1){
                dp[i][j]=arr[i][j];
            }
            else if(j==m-1){
                dp[i][j]=arr[i][j];
            }
            else{
                if(arr[i][j]==0){
                    dp[i][j]=0;
                }
                else{
                dp[i][j]=std::min(std::min(dp[i+1][j+1],dp[i][j+1]),dp[i+1][j])+1;
                if(dp[i][j]>ans){
                    ans=dp[i][j];
                }
                }

            }
        }
        }   
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cout<<dp[i][j];
        }
        std::cout<<"\n";
    }
    std::cout<<ans;

return 0;
}