#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[]){
    int n,k;
    std::cin>>n>>k;
    std::vector<std::vector<ll>>dp(k+1,std::vector<ll>(n+1,0));
    if(n==0 || k==0 || n<k){
        return 0;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dp[i][j]=1;
            }
            else if(j<i){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1]*i;
            }
        }
    }
    std::cout<<dp[k][n];
return 0;
}